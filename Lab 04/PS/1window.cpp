
#include <FL/Fl.H> // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class

int main(int argc, char *argv[]) {
    	Fl_Window *window;

window = new Fl_Window (600,600,"DEMO"); // outer window

    	window->end();
    	window->show();
    	return(Fl::run());  // the process waits from here on for events
}


