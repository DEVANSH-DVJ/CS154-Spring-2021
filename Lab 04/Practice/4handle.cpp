#include <FL/Fl.H>              // needed in every fltk program
#include <FL/Fl_Button.H>       // needed to use the Fl_Box class
#include <FL/Fl_Light_Button.H> // needed to use the Fl_Box class
#include <FL/Fl_Radio_Button.H> // needed to use the Fl_Box class
#include <FL/Fl_Window.H>       // needed to use the Fl_Window class

class MyButton : public Fl_Button {
  int state;

public:
  MyButton(int x, int y, int w, int h, const char *l);
  int handle(int e); // e is incoming mouse event of different kinds
};

MyButton ::MyButton(int x, int y, int w, int h, const char *l)
    : Fl_Button(x, y, w, h, l) {
  state = 0;
}

int MyButton ::handle(int e) {
  if (state == 0) {
    this->label("00");
    state = 1;
  } else {
    this->label("11");
    state = 0;
  }
  return 1;
};

int main(int argc, char *argv[]) {
  Fl_Window *window;

  window = new Fl_Window(600, 600, "DEMO"); // outer window

  Fl_Button *button1 = new MyButton(100, 100, 100, 100, "Box 1!");
  window->color(FL_WHITE);
  button1->down_color(FL_RED);

  button1->label("10");

  window->end();
  window->show();
  return (Fl::run()); // the process waits from here on for events
}
