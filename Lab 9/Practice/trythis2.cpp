/**
 * Author: Devansh Jain (190100044)
 * Lab 9 - Postfix and Prefix incrementation inside three parameter functions
 */

#include <iostream>
using namespace std;

void f(int x, int y, int z) { cout << x << " " << y << " " << z << endl; }

int main() {

  int i = 10;

  f(i++, ++i, ++i); // 12 13 13
  cout << i << endl; // 13

  f(++i, i++, ++i); // 16 14 16
  cout << i << endl; // 16

  f(++i, ++i, ++i); // 19 19 19
  cout << i << endl; // 19

  return 0;
}
