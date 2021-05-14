/**
 * Author: Devansh Jain (190100044)
 * Lab 9 - Prefix and Postfix Operators
 */

#include <iostream>
using namespace std;

class A {
  int v;

public:
  A(int x) { v = x; }
  void operator++() { cout << "Prefix operator called \n"; }
  void operator++(int) { cout << "Postfix operator called \n"; }
};

int main() {

  A a(10);
  ++a;
  a++;

  return 0;
}
