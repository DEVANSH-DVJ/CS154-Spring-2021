#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>
#include <FL/fl_ask.H> // fl_message
#include <Fl/Fl_Box.H>

// Global variables as they are used in callback functions
Fl_Window *window1 = nullptr; // New game window
Fl_Window *window2 = nullptr; // Play Game window
char *playing = (char *)"";   // Label of current player

/**
 * @class tictactoe
 * @brief contains the logic for playing the game
 */
class tictactoe {
private:
  int count;          // Stores count of boxes filled
  Fl_Button *bArr[9]; // Array of Buttons
  char *player1;      // Label of player1
  char *player2;      // Label of player2

public:
  /**
   * @fn tictactoe
   * @brief constructor of class tictactoe
   *        allocates the button
   */
  tictactoe();

  /**
   * @fn gameWon
   * @return bool if the game has been won upon the last click
   * @brief checks all the 8 possible cases of winning
   */
  bool gameWon();

  // Friend function
  friend void btnCallBack(Fl_Widget *w, void *v);
};

void btnCallBack(Fl_Widget *w, void *v);
void nextpage(Fl_Widget *w, void *v);
void close(Fl_Widget *w, void *v);

tictactoe::tictactoe() {
  count = 0;
  player1 = (char *)"X";
  player2 = (char *)"O";

  int X = 20;
  int Y = 20;
  int W = 90;
  int H = 90;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int loop = 3 * i + j;
      bArr[loop] = new Fl_Button(X, Y, W, H, 0);
      bArr[loop]->callback(btnCallBack, this);
      X += 90;
    }
    X = 20;
    Y += 90;
  }
}

bool tictactoe::gameWon() {
  char *ip = playing;
  return ((bArr[0]->label() == ip) && (bArr[1]->label() == ip) &&
              (bArr[2]->label() == ip) ||
          (bArr[3]->label() == ip) && (bArr[4]->label() == ip) &&
              (bArr[5]->label() == ip) ||
          (bArr[6]->label() == ip) && (bArr[7]->label() == ip) &&
              (bArr[8]->label() == ip) ||
          (bArr[0]->label() == ip) && (bArr[3]->label() == ip) &&
              (bArr[6]->label() == ip) ||
          (bArr[1]->label() == ip) && (bArr[4]->label() == ip) &&
              (bArr[7]->label() == ip) ||
          (bArr[2]->label() == ip) && (bArr[5]->label() == ip) &&
              (bArr[8]->label() == ip) ||
          (bArr[0]->label() == ip) && (bArr[4]->label() == ip) &&
              (bArr[8]->label() == ip) ||
          (bArr[2]->label() == ip) && (bArr[4]->label() == ip) &&
              (bArr[6]->label() == ip));
}

void btnCallBack(Fl_Widget *w, void *v) {
  tictactoe *game = (tictactoe *)v;

  if (w->label() == "X" || w->label() == "O") {
    return;
  }

  game->count++;
  w->label(playing);
  w->labelsize(30);

  if (game->gameWon()) {
    fl_message("'%s' Won the game..Congrats..!!", playing);
    for (int i = 0; i < 9; i++)
      game->bArr[i]->label("");
    game->count = 0;
    window1->show();
    window2->hide();
    return;
  } else if (game->count == 9) {
    fl_message("The Game is a tie");
    for (int i = 0; i < 9; i++)
      game->bArr[i]->label("");
    game->count = 0;
    window1->show();
    window2->hide();
    return;
  } else {
    if (playing == game->player1)
      playing = game->player2;
    else
      playing = game->player1;
  }
}

void nextpage(Fl_Widget *w, void *v) {
  playing = (char *)w->label();
  window1->hide();
  window2->show();
}

void close(Fl_Widget *w, void *v) { exit(0); }

int main(int argc, char *argv[]) {

  window1 = new Fl_Window(500, 250, 310, 310, "Select An Option");

  Fl_Box *textbox =
      new Fl_Box(60, 60, 200, 60, "Select an option\n to start the game");
  textbox->labelsize(20);

  Fl_Button *choice1 = new Fl_Button(100, 130, 100, 30, "X");
  Fl_Button *choice2 = new Fl_Button(100, 170, 100, 30, "O");
  Fl_Button *exit = new Fl_Button(70, 210, 160, 60, "Exit");
  exit->labelsize(20);
  choice1->labelsize(20);
  choice2->labelsize(20);
  exit->labelfont(FL_ITALIC + FL_HELVETICA);
  choice1->labelfont(FL_ITALIC);
  choice2->labelfont(FL_ITALIC);
  exit->callback(close);
  choice1->callback(nextpage);
  choice2->callback(nextpage);
  window1->end();
  window1->show();

  window2 = new Fl_Window(500, 250, 310, 310, "Play Game");
  tictactoe B;
  window2->end();
  window2->hide();

  return Fl::run();
}
