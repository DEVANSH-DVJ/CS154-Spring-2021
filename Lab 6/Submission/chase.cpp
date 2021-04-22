/**
 * Author: Devansh Jain (190100044)
 * Lab 6 - The Chase
 */

#include <FL/Fl.H>        // Fl::run()
#include <FL/Fl_Button.H> // Fl_Button
#include <FL/Fl_Window.H> // Fl_Window
#include <FL/fl_ask.H>    // fl_message
#include <FL/fl_draw.H>   // fl_rectf
#include <Fl/Fl_Box.H>    // Fl_Box

// Forward Declaration
class Chase;

/**
 * @class Shape
 * @brief Inherits from Fl_Widget
 *        Base class for Player and Boundary
 */
class Shape : public Fl_Widget {
protected:
  int x, y, w, h; // Dimensions

public:
  /**
   * @fn Shape
   * @param[in] x x coordinate of top-left corner
   * @param[in] y y coordinate of top-left corner
   * @param[in] w width of widget
   * @param[in] h height of widget
   * @brief constructor of class Shape
   */
  Shape(int x, int y, int w, int h);

  /**
   * @fn refresh
   * @param[in] dx change in x
   * @param[in] dy change in y
   * @brief virtual function, does nothing as of now
   */
  virtual void refresh(int dx, int dy);

  /**
   * @fn handle
   * @param[in] e event
   * @brief virtual function, does nothing as of now
   */
  virtual int handle(int e);
};

/**
 * @class Player
 * @brief Inherits from Shape
 *        Represents the players
 */
class Player : public Shape {
  uint steps;    // Step counter
  bool chaser;   // is chaser?
  int s;         // side length
  int m;         // movement per step
  Chase *master; // pointer to the Chase object

  /**
   * @fn left
   * @brief checks and moves the player to left
   */
  int left();

  /**
   * @fn right
   * @brief checks and moves the player to right
   */
  int right();

  /**
   * @fn up
   * @brief checks and moves the player to up
   */
  int up();

  /**
   * @fn down
   * @brief checks and moves the player to down
   */
  int down();

  /**
   * @fn refresh
   * @param[in] dx change in x
   * @param[in] dy change in y
   * @brief changes the position of the player by (dx, dy) and redraws
   */
  void refresh(int dx, int dy);

public:
  /**
   * @fn Player
   * @param[in] x x coordinate of center
   * @param[in] y y coordinate of center
   * @param[in] s side length of widget
   * @param[in] chaser whether the player is chaser or not
   * @param[in] master pointer to the Chase object
   * @brief constructor of class Player
   */
  Player(int x, int y, int s, bool chaser, Chase *master);

  /**
   * @fn reset
   * @param[in] x reset x coordinate
   * @param[in] y reset y coordinate
   * @brief resets the position of the player to (x,y) and steps to 0
   */
  void reset(int x, int y);

  /**
   * @fn draw
   * @brief draws the player on the arena
   */
  void draw();

  /**
   * @fn handle
   * @param[in] e event
   * @brief handles keyboard events
   */
  int handle(int e);

  /**
   * @fn get_loc
   * @param[out] x saves x coordinate of the player
   * @param[out] y saves y coordinate of the player
   * @brief saves coordinates of the player
   */
  void get_loc(int &x, int &y);

  /**
   * @fn get_steps
   * @return step counter
   * @brief return steps
   */
  uint get_steps();
};

/**
 * @class Boundary
 * @brief Inherits from Shape
 *        Represents Arena Boundary
 */
class Boundary : public Shape {
public:
  /**
   * @fn Boundary
   * @param[in] x x coordinate of top-left corner
   * @param[in] y y coordinate of top-left corner
   * @param[in] w width of widget
   * @param[in] h height of widget
   * @brief constructor of class Boundary
   */
  Boundary(int x, int y, int w, int h);

  /**
   * @fn draw
   * @brief draws the boundary of the arena
   */
  void draw();
};

class Chase {
  Fl_Window *window1;      // New Game window
  Fl_Window *window2;      // Play Game window
  Fl_Box *textbox;         // TextBox for New Game Window
  Fl_Button *play, *close; // Buttons for New Game Window
  Player *p1, *p2;         // Players
  Boundary *b;             // Boundary for the Arena

  /**
   * @fn finish
   * @param[in] chased whether the chaser win
   * @brief resets the game and displays who won
   */
  void finish(bool chased);

  /**
   * @fn init_window1
   * @brief initializes play and exit buttons
   */
  void init_window1();

  /**
   * @fn init_window2
   * @brief initializes arena and the players
   */
  void init_window2();

public:
  /**
   * @fn Chase
   * @brief constructor of class TicTacToe
   */
  Chase();

  /**
   * @fn ~Chase
   * @brief destructor of class Chaser
   */
  ~Chase();

  /**
   * @fn game_won
   * @brief checks if either of the players won
   */
  void check();

  /**
   * @fn nextpage_callback
   * @param[in] w pointer to the widget object which is clicked
   * @param[in] v pointer to the Chase object
   * @brief called whenever a button is clicked (play)
   */
  static void nextpage_callback(Fl_Widget *w, void *v);

  /**
   * @fn close_callback
   * @param[in] w pointer to the widget object which is clicked
   * @param[in] v pointer to the Chase object
   * @brief called whenever a button is clicked (exit)
   */
  static void close_callback(Fl_Widget *w, void *v);
};

Shape::Shape(int x, int y, int w, int h) : Fl_Widget(x, y, w, h) {
  this->x = x;
  this->y = y;
  this->w = w;
  this->h = h;
}

void Shape::refresh(int dx, int dy){};

int Shape::handle(int e) { return 0; };

Player::Player(int x, int y, int s, bool chaser, Chase *master)
    : Shape(x, y, s, s) {
  this->m = 10;
  this->s = s;
  this->chaser = chaser;
  this->steps = 0;
  this->master = master;
}

int Player::left() {
  if (x - m - s / 2 > 100) {
    refresh(-m, 0);
    steps++;
    master->check();
  }
  return 1;
}

int Player::right() {
  if (x + m + s / 2 < 500) {
    refresh(m, 0);
    steps++;
    master->check();
  }
  return 1;
}

int Player::up() {
  if (y - m - s / 2 > 100) {
    refresh(0, -m);
    steps++;
    master->check();
  }
  return 1;
}

int Player::down() {
  if (y + m + s / 2 < 500) {
    refresh(0, m);
    steps++;
    master->check();
  }
  return 1;
}

void Player::refresh(int dx, int dy) {
  x = x + dx;
  y = y + dy;
  resize(x, y, w, h);
  Fl::redraw();
}

void Player::reset(int x, int y) {
  refresh(x - this->x, y - this->y);
  steps = 0;
}

void Player::draw() {
  if (chaser)
    fl_rectf(x - s / 2, y - s / 2, s, s, FL_RED);
  else
    fl_rectf(x - s / 2, y - s / 2, s, s, FL_BLUE);
}

int Player::handle(int e) {
  if (e == FL_SHORTCUT) {
    if (chaser) {
      switch (Fl::event_key()) {
      case FL_Left:
        return left();

      case FL_Right:
        return right();

      case FL_Up:
        return up();

      case FL_Down:
        return down();

      default:
        break;
      }
    } else {
      switch (Fl::event_key()) {
      case 'a':
        return left();

      case 'd':
        return right();

      case 'w':
        return up();

      case 's':
        return down();

      default:
        break;
      }
    }
  }
  return 0;
};

void Player::get_loc(int &x, int &y) {
  x = this->x;
  y = this->y;
}

uint Player::get_steps() { return steps; }

Boundary::Boundary(int x, int y, int w, int h) : Shape(x, y, w, h) {}

void Boundary::draw() { fl_rectf(x, y, w, h, 0xdddddd00); }

Chase::Chase() {
  init_window1();
  init_window2();
}

Chase::~Chase() { delete window1, window2, textbox, play, close, b, p1, p2; }

void Chase::finish(bool chased) {
  if (chased)
    fl_message("Chaser wins! Chased down in %i steps", p2->get_steps());
  else
    fl_message("Escapee wins! Chaser took 1000 steps");
  p1->reset(300, 120);
  p2->reset(300, 480);

  window1->show();
  window2->hide();
};

void Chase::init_window1() {
  window1 = new Fl_Window(600, 600, "New Game");

  // Textbox
  textbox = new Fl_Box(100, 50, 400, 200,
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

void Chase::init_window2() {
  window2 = new Fl_Window(600, 600, "Play Game");

  // Arena
  window2->color(0x22222200);
  b = new Boundary(100, 100, 400, 400);

  // Players
  p1 = new Player(300, 120, 20, false, this);
  p2 = new Player(300, 480, 20, true, this);

  window2->end();
  window2->hide();
}

void Chase::check() {
  int x1, y1, x2, y2;
  p1->get_loc(x1, y1);
  p2->get_loc(x2, y2);
  if (abs(x1 - x2) < 20 && abs(y1 - y2) < 20)
    return finish(true);
  if (p2->get_steps() >= 1000)
    return finish(false);
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
