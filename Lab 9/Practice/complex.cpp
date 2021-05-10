// program by Prof. R.K.Joshi
// for CS152, IIT Bombay

#include <iostream>
using namespace std;

// observe definition of our own operator for use with objects,
// which means for use with values which are not primitive data types
// note the associativity from right to left

class Complex {
  float i, j;

public:
  Complex(int x, int y) {
    i = x;
    j = y;
  }

  Complex operator+(Complex c) {
    cout << i << "," << j << "+" << c.i << "," << c.j << endl;
    return Complex(i + c.i, j + c.j);
  }

  void prn() { cout << i << "," << j << endl; }
};

int main() {

  Complex c1(10, 10), c2(20, 20), c3(0, 0);

  c3 = c1 + c2;

  c3.prn();

  c3 = c3 + c1 + c2 + c2;

  c3.prn();
}
