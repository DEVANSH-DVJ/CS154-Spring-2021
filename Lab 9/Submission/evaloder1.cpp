/**
 * Author: Devansh Jain (190100044)
 * Lab 9 - Evaluation Order
 */

#include <iostream>
using namespace std;

int p = 1;

int f(int i) {
  p = p + i;
  return p;
}

int main() {

  cout << f(p) << " " << f(p) << " " << f(p) << " " << f(++p) << endl; // 2 4 8 18

  p = 1;
  cout << f(p) << " " << f(p) << " " << f(p) << " " << f(p++) << endl; // 2 4 8 17

  p = 1;
  cout << f(++p) << " " << f(p) << " " << f(p) << " " << f(p) << endl; // 4 8 16 32

  p = 1;
  cout << f(p++) << " " << f(p) << " " << f(p) << " " << f(p) << endl; // 3 6 12 24

  return 0;
}
