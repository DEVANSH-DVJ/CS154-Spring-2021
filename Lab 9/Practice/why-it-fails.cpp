/**
 * Author: Devansh Jain (190100044)
 * Lab 9 - Operator precedence order
 */

#include <iostream>
using namespace std;

int main() {

  bool a = true, b = true;

  // cout << a || b << endl; // Compile Time Error
  cout << (a || b) << endl; // Works fine

  return 0;
}
