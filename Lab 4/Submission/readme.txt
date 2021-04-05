I wasn't able to follow sir for 15 Puzzle Game due to internet issues.
After confirming with TA Khyati Oswal, I instead created a tic-tac-toe game.

Compiling and play: g++ tictactoe.cpp -lfltk -o tictactoe; ./tictactoe;

Major FLTK event handler I used was callback for buttons.
The entire game is inside the class TicTacToe.
It contains two windows - New Game window and Play Game window.
New Game window has 3 buttons, two for choosing the label for first player and one for exiting.
Play Game window has a 3x3 grid of buttons which get labels when clicked.
It also has three static functions which are callback functions for the buttons -
  close_callback() for exit button,
  nextpage_callback() for choosing the label button, and
  grid_callback() for the 3x3 grid buttons.

The code is commented properly and the working of each function is understandable.
