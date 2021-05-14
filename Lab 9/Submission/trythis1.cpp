/**
 * Author: Devansh Jain (190100044)
 * Lab 9 - Postfix and Prefix incrementation inside two parameter functions
 */

#include <iostream>
using namespace std;

void f(int x, int y) { cout << x << " " << y << endl; }

int main() {

  int i = 10;

  f(i++, ++i); // 11 12
  cout << i << endl; // 12

  f(++i, i++); // 14 12
  cout << i << endl; // 14

  f(i, i++); // 15 14
  cout << i << endl; // 15

  f(i, ++i); // 16 16
  cout << i << endl; // 16

  return 0;
}
