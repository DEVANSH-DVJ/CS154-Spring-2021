#include <FL/Fl.H>        // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class
#include <Fl/Fl_Button.H> // needed to use the Fl_Button class

int main(int argc, char *argv[]) {
  Fl_Window *window = new Fl_Window(800, 600, "DEMO"); // outer window

  Fl_Button *button1 = new Fl_Button(100, 100, 100, 100, "Button1");
  Fl_Button *button2 = new Fl_Button(300, 300, 100, 100, "Button2");

  window->end();
  window->show();

  return (Fl::run()); // the process waits from here on for events
}
