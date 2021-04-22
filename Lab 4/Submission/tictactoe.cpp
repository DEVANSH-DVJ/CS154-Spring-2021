/**
 * Author: Devansh Jain (190100044)
 * Lab 4 - Tic Tac Toe
 */

#include <FL/Fl.H>        // Fl::run()
#include <FL/Fl_Button.H> // Fl_Button
#include <FL/Fl_Window.H> // Fl_Window
#include <FL/fl_ask.H>    // fl_message
#include <Fl/Fl_Box.H>    // Fl_Box

/**
 * @class TicTacToe
 * @brief contains the logic for playing the game
 */
class TicTacToe {
private:
  Fl_Window *window1;                   // New Game window
  Fl_Window *window2;                   // Play Game window
  Fl_Box *textbox;                      // TextBox for New Game Window
  Fl_Button *choice1, *choice2, *close; // Buttons for New Game Window
  Fl_Button *bArr[3][3];                // Array of Buttons for Play Game Window

  int count; // Stores count of boxes filled

  char *playing; // Label of current player
  char *player1; // Label of player1
  char *player2; // Label of player2

public:
  /**
   * @fn TicTacToe
   * @brief constructor of class TicTacToe
   */
  TicTacToe();

  /**
   * @fn ~TicTacToe
   * @brief destructor of class TicTacToe
   */
  ~TicTacToe();

  /**
   * @fn init_window1
   * @brief initializes window1 and allocates the 3 buttons
   */
  void init_window1();

  /**
   * @fn init_window2
   * @brief initializes window2 and allocates 3x3 grid button
   */
  void init_window2();

  /**
   * @fn game_won
   * @return bool if the game has been won upon the last click
   * @brief checks all the 8 possible cases of winning
   */
  bool game_won();

  /**
   * @fn grid_callback
   * @param[in] w pointer to the widget object which is clicked
   * @param[in] v pointer to the TicTacToe object
   * @brief called whenever a button in the 3x3 grid is clicked
   */
  static void grid_callback(Fl_Widget *w, void *v);

  /**
   * @fn nextpage_callback
   * @param[in] w pointer to the widget object which is clicked
   * @param[in] v pointer to the TicTacToe object
   * @brief called whenever a button is clicked (choice of player)
   */
  static void nextpage_callback(Fl_Widget *w, void *v);

  /**
   * @fn close_callback
   * @param[in] w pointer to the widget object which is clicked
   * @param[in] v pointer to the TicTacToe object
   * @brief called whenever a button is clicked (exit)
   */
  static void close_callback(Fl_Widget *w, void *v);
};

TicTacToe::TicTacToe() {
  window1 = nullptr;
  window2 = nullptr;
  textbox = nullptr;
  choice1 = nullptr;
  choice2 = nullptr;
  close = nullptr;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      bArr[i][j] = nullptr;

  count = 0;

  playing = (char *)"";
  player1 = (char *)"X";
  player2 = (char *)"O";

  init_window1();
  init_window2();
}

TicTacToe::~TicTacToe() {
  delete window1, window2, textbox, choice1, choice2, close;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      delete bArr[i][j];
}

void TicTacToe::init_window1() {
  // Init Window 1
  window1 = new Fl_Window(500, 250, 310, 310, "New Game");

  // Textbox
  textbox = new Fl_Box(60, 60, 200, 60, "Select an option\n to start the game");
  textbox->labelsize(20);

  // "X" button
  choice1 = new Fl_Button(100, 130, 100, 30, "X");
  choice1->labelsize(20);
  choice1->labelfont(FL_ITALIC);
  choice1->callback(&TicTacToe::nextpage_callback, this);

  // "O" button
  choice2 = new Fl_Button(100, 170, 100, 30, "O");
  choice2->labelsize(20);
  choice2->labelfont(FL_ITALIC);
  choice2->callback(&TicTacToe::nextpage_callback, this);

  // Exit button
  close = new Fl_Button(70, 210, 160, 60, "Exit");
  close->labelsize(20);
  close->labelfont(FL_ITALIC + FL_HELVETICA);
  close->callback(&TicTacToe::close_callback, this);

  window1->end();
  window1->show();
}

void TicTacToe::init_window2() {
  // Init Window 2
  window2 = new Fl_Window(500, 250, 310, 310, "Play Game");

  // Construct buttons
  int X = 20;
  int Y = 20;
  int W = 90;
  int H = 90;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      bArr[i][j] = new Fl_Button(X, Y, W, H, 0);
      bArr[i][j]->callback(grid_callback, this);
      X += 90;
    }
    X = 20;
    Y += 90;
  }

  window2->end();
  window2->hide();
}

bool TicTacToe::game_won() {
  char *ip = playing;

  return ((bArr[0][0]->label() == ip) && (bArr[0][1]->label() == ip) &&
              (bArr[0][2]->label() == ip) ||
          (bArr[1][0]->label() == ip) && (bArr[1][1]->label() == ip) &&
              (bArr[1][2]->label() == ip) ||
          (bArr[2][0]->label() == ip) && (bArr[2][1]->label() == ip) &&
              (bArr[2][2]->label() == ip) ||
          (bArr[0][0]->label() == ip) && (bArr[1][0]->label() == ip) &&
              (bArr[2][0]->label() == ip) ||
          (bArr[0][1]->label() == ip) && (bArr[1][1]->label() == ip) &&
              (bArr[2][1]->label() == ip) ||
          (bArr[0][2]->label() == ip) && (bArr[1][2]->label() == ip) &&
              (bArr[2][2]->label() == ip) ||
          (bArr[0][0]->label() == ip) && (bArr[1][1]->label() == ip) &&
              (bArr[2][2]->label() == ip) ||
          (bArr[0][2]->label() == ip) && (bArr[1][1]->label() == ip) &&
              (bArr[2][0]->label() == ip));
}

void TicTacToe::grid_callback(Fl_Widget *w, void *v) {
  // Get the self object
  TicTacToe *self = (TicTacToe *)v;

  // Check if button is already labelled
  if (w->label() == "X" || w->label() == "O") {
    return;
  }

  // If not then add the label
  self->count++;
  w->label(self->playing);
  w->labelsize(30);

  if (self->game_won()) {
    // If game is won by someone
    fl_message("'%s' won the Game. Congrats!!", self->playing);
  } else if (self->count == 9) {
    // If all buttons are labelled
    fl_message("The Game is a tie.");
  } else {
    // Switch playing person (and its label)
    if (self->playing == self->player1)
      self->playing = self->player2;
    else
      self->playing = self->player1;
    return;
  }

  // If game ended (won by someone or tied)
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      self->bArr[i][j]->label("");
  self->count = 0;
  self->window1->show();
  self->window2->hide();
  return;
}

void TicTacToe::nextpage_callback(Fl_Widget *w, void *v) {
  // Get the self object
  TicTacToe *self = (TicTacToe *)v;

  // Set the playing as the label first player chose
  self->playing = (char *)w->label();

  // Switch windows
  self->window1->hide();
  self->window2->show();
}

void TicTacToe::close_callback(Fl_Widget *w, void *v) {
  // Get the self object
  TicTacToe *self = (TicTacToe *)v;

  self->~TicTacToe();
  exit(0);
}

int main(int argc, char *argv[]) {
  TicTacToe B; // Initialize the game

  return Fl::run(); // Game flows till exited
}
