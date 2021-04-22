#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>
#include <FL/fl_ask.H>
#include <FL/fl_draw.H>
#include <iostream>

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
  int id;
  uint steps;
  bool chaser;
  int s;
  int m;

  void left() {
    if (x - m - s / 2 > 100) {
      refresh(-m, 0);
      steps++;
    }
  }

  void right() {
    if (x + m + s / 2 < 500) {
      refresh(m, 0);
      steps++;
    }
  }

  void up() {
    if (y - m - s / 2 > 100) {
      refresh(0, -m);
      steps++;
    }
  }

  void down() {
    if (y + m + s / 2 < 500) {
      refresh(0, m);
      steps++;
    }
  }

public:
  Player(int x, int y, int s, int player_id, bool chaser) : Shape(x, y, s, s) {
    this->m = 10;
    this->s = s;
    this->id = player_id;
    this->steps = 0;
    this->chaser = chaser;
  }

  void draw() {
    if (chaser)
      fl_rectf(x - s / 2, y - s / 2, s, s, FL_RED);
    else
      fl_rectf(x - s / 2, y - s / 2, s, s, FL_BLUE);
  }

  void refresh(int dx, int dy) {
    x = x + dx;
    y = y + dy;
    resize(x, y, w, h);
    Fl::redraw();
  }

  int handle(int e) {
    if (e == FL_SHORTCUT) {
      if (id == 0) {
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
      } else if (id == 1) {
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
};

class Boundary : public Shape {
public:
  Boundary(int x, int y, int h, int w) : Shape(x, y, h, w) {}

  void draw() { fl_draw_box(FL_FLAT_BOX, x, y, h, w, 0xdddddd00); }
};

int main(int argc, char *argv[]) {
  Fl_Window *window;
  window = new Fl_Window(600, 600, "Play");       // outer window
  Boundary *b = new Boundary(100, 100, 400, 400); // Message at Finishing line
  Player *p1 = new Player(300, 120, 20, 0, false);
  Player *p2 = new Player(300, 480, 20, 1, true);
  window->color(0x22222200);
  window->end();
  window->show();

  return (Fl::run()); // the process waits from here on for events
}
