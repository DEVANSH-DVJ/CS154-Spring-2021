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

  cout << f(p) << " " << f(p) << " " << f(p) << " " << f(++p) << endl;

  p = 1;
  cout << f(p) << " " << f(p) << " " << f(p) << " " << f(p++) << endl;

  p = 1;
  cout << f(++p) << " " << f(p) << " " << f(p) << " " << f(p) << endl;

  p = 1;
  cout << f(p++) << " " << f(p) << " " << f(p) << " " << f(p) << endl;

  return 0;
}
