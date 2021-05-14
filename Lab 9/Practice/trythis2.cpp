/**
 * Author: Devansh Jain (190100044)
 * Lab 9 - Postfix and Prefix incrementation inside three parameter functions
 */

#include <iostream>
using namespace std;

void f(int x, int y, int z) { cout << x << " " << y << " " << z << endl; }

int main() {

  int i = 10;

  f(i++, ++i, ++i);
  cout << i << endl;

  f(++i, i++, ++i);
  cout << i << endl;

  f(++i, ++i, ++i);
  cout << i << endl;

  return 0;
}
