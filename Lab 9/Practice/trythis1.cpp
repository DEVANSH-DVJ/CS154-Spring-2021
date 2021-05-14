/**
 * Author: Devansh Jain (190100044)
 * Lab 9 - Postfix and Prefix incrementation inside two parameter functions
 */

#include <iostream>
using namespace std;

void f(int x, int y) { cout << x << " " << y << endl; }

int main() {

  int i = 10;

  f(i++, ++i);
  cout << i << endl;

  f(++i, i++);
  cout << i << endl;

  f(i, i++);
  cout << i << endl;

  f(i, ++i);
  cout << i << endl;

  return 0;
}
