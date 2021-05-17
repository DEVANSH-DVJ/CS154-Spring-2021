#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>
#include <FL/fl_ask.H>
#include <FL/fl_draw.H>
#include <Fl/Fl_Box.H> // Fl_Box
#include <iostream>

class Chase;

class Shape : public Fl_Widget {
protected:
  int x, y, w, h;

public:
  Shape(int x, int y, int w, int h) : Fl_Widget(x, y, w, h) {
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
  }
  virtual void refresh(int dx, int dy){};
  virtual int handle(int e) { return 0; };
};

class Player : public Shape {
  uint steps;
  bool chaser;
  int s;
  int m;
  Chase *master;

  void left();
  void right();
  void up();
  void down();
  void refresh(int dx, int dy) {
    x = x + dx;
    y = y + dy;
    resize(x, y, w, h);
    Fl::redraw();
  }

public:
  Player(int x, int y, int s, bool chaser, Chase *master) : Shape(x, y, s, s) {
    this->m = 10;
    this->s = s;
    this->chaser = chaser;
    this->steps = 0;
    this->master = master;
  }

  void reset(int x, int y) {
    refresh(x - this->x, y - this->y);
    steps = 0;
  }

  void draw() {
    if (chaser)
      fl_rectf(x - s / 2, y - s / 2, s, s, FL_RED);
    else
      fl_rectf(x - s / 2, y - s / 2, s, s, FL_BLUE);
  }

  int handle(int e) {
    if (e == FL_SHORTCUT) {
      if (chaser) {
        switch (Fl::event_key()) {
        case FL_Left:
          left();
          return 1;
          break;

        case FL_Right:
          right();
          return 1;
          break;

        case FL_Up:
          up();
          return 1;
          break;

        case FL_Down:
          down();
          return 1;
          break;

        default:
          break;
        }
      } else {
        switch (Fl::event_key()) {
        case 'a':
          left();
          return 1;
          break;

        case 'd':
          right();
          return 1;
          break;

        case 'w':
          up();
          return 1;
          break;

        case 's':
          down();
          return 1;
          break;

        default:
          break;
        }
      }
    }
    return 0;
  };

  void get_loc(int &x, int &y) {
    x = this->x;
    y = this->y;
  }

  uint get_steps() { return steps; }
};

class Boundary : public Shape {
public:
  Boundary(int x, int y, int w, int h) : Shape(x, y, w, h) {}

  void draw() { fl_draw_box(FL_FLAT_BOX, x, y, w, h, 0xdddddd00); }
};

class Chase {
  Fl_Window *window1;
  Fl_Window *window2;
  Fl_Button *play, *close;
  Fl_Box *textbox;
  Player *p1, *p2;
  Boundary *b;

  void finish(bool chased) {
    if (chased)
      fl_message("Chaser wins! Chased down in %i steps", p2->get_steps());
    else
      fl_message("Escapee wins! Chaser took 1000 steps");
    p1->reset(300, 120);
    p2->reset(300, 480);

    window1->show();
    window2->hide();
  };

public:
  Chase() {
    init_window1();
    init_window2();
  }

  void init_window1() {
    window1 = new Fl_Window(600, 600, "New Game");

    // Textbox
    textbox =
        new Fl_Box(100, 50, 400, 200,
                   "Instructions:\n\n"
                   "Chaser (red) uses WASD keys to move and needs catch \n"
                   "the escapee in less than 1000 steps.\n"
                   "Escapee (blue) uses arrow keys to move and needs to \n"
                   "escape the chaser for 1000 steps.\n");
    textbox->labelsize(20);

    // Play button
    play = new Fl_Button(200, 250, 200, 100, "Play");
    play->labelsize(20);
    play->labelfont(FL_ITALIC + FL_HELVETICA);
    play->callback(&Chase::nextpage_callback, this);

    // Exit button
    close = new Fl_Button(200, 400, 200, 100, "Exit");
    close->labelsize(20);
    close->labelfont(FL_ITALIC + FL_HELVETICA);
    close->callback(&Chase::close_callback, this);

    window1->end();
    window1->show();
  }

  void init_window2() {
    window2 = new Fl_Window(600, 600, "Play Game");
    window2->color(0x22222200);

    b = new Boundary(100, 100, 400, 400);
    p1 = new Player(300, 120, 20, false, this);
    p2 = new Player(300, 480, 20, true, this);

    window2->end();
    window2->hide();
  }

  void check() {
    int x1, y1, x2, y2;
    p1->get_loc(x1, y1);
    p2->get_loc(x2, y2);
    if (abs(x1 - x2) < 20 && abs(y1 - y2) < 20)
      return finish(true);
    if (p2->get_steps() >= 1000)
      return finish(false);
  }

  static void nextpage_callback(Fl_Widget *w, void *v);

  static void close_callback(Fl_Widget *w, void *v);
};

void Player::left() {
  if (x - m - s / 2 > 100) {
    refresh(-m, 0);
    steps++;
    master->check();
  }
}

void Player::right() {
  if (x + m + s / 2 < 500) {
    refresh(m, 0);
    steps++;
    master->check();
  }
}

void Player::up() {
  if (y - m - s / 2 > 100) {
    refresh(0, -m);
    steps++;
    master->check();
  }
}

void Player::down() {
  if (y + m + s / 2 < 500) {
    refresh(0, m);
    steps++;
    master->check();
  }
}

void Chase::nextpage_callback(Fl_Widget *w, void *v) {
  // Get the self object
  Chase *self = (Chase *)v;

  // Switch windows
  self->window1->hide();
  self->window2->show();
}

void Chase::close_callback(Fl_Widget *w, void *v) {
  // Get the self object
  Chase *self = (Chase *)v;

  self->~Chase();
  exit(0);
}

int main(int argc, char *argv[]) {
  Chase C;

  return (Fl::run()); // the process waits from here on for events
}
