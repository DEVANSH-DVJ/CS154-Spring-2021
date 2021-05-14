/**
 * Author: Devansh Jain (190100044)
 * Lab 9 - Left and Right side of assignment
 */

#include <iostream>
using namespace std;

int main() {

  int x = 10;

  ++x = x++;         // this is acceptable
  cout << x << endl; // 10

  x = 10;
  ++x = ++x;         // this is acceptable
  cout << x << endl; // 12

  x = 10;
  ++x = x;           // this is acceptable
  cout << x << endl; // 11

  x = 10;
  x = x++;           // this is acceptable
  cout << x << endl; // 10

  x = 10;
  x = ++x;           // this is acceptable
  cout << x << endl; // 11

  // x++ = x++;  // but this is not... why?!

  return 0;
}
