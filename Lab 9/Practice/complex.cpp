/**
 * Author: Devansh Jain (190100044)
 * Lab 9 - Complex - cascading/nesting of operators
 */

#include <iostream>
using namespace std;

// observe definition of our own operator for use with objects,
// which means for use with values which are not primitive data types
// note the associativity from right to left

class Complex {
  float i, j;

public:
  Complex() : Complex(0, 0) {}

  Complex(float x, float y) {
    i = x;
    j = y;
  }

  Complex operator+(Complex c) {
    cout << "(" << i << " + i" << j << ")"
         << " + "
         << "(" << c.i << " + i" << c.j << ")"
         << " = "
         << "(" << i + c.i << " + i" << j + c.j << ")" << endl;
    return Complex(i + c.i, j + c.j);
  }

  Complex operator-(Complex c) {
    cout << "(" << i << " + i" << j << ")"
         << " - "
         << "(" << c.i << " + i" << c.j << ")"
         << " = "
         << "(" << i - c.i << " + i" << j - c.j << ")" << endl;
    return Complex(i - c.i, j - c.j);
  }

  Complex operator*(Complex c) {
    cout << "(" << i << " + i" << j << ")"
         << " * "
         << "(" << c.i << " + i" << c.j << ")"
         << " = "
         << "(" << i * c.i - j * c.j << " + i" << i * c.j + j * c.i << ")"
         << endl;
    return Complex(i * c.i - j * c.j, i * c.j + j * c.i);
  }

  Complex operator/(Complex c) {
    // Check division by zero
    if (c.i == 0 && c.j == 0) {
      cout << "Can't divide by 0" << endl;
      return Complex();
    }

    float mod = c.i * c.i + c.j * c.j;
    cout << "(" << i << " + i" << j << ")"
         << " / "
         << "(" << c.i << " + i" << c.j << ")"
         << " = "
         << "(" << (i * c.i + j * c.j) / mod << " + i"
         << (j * c.i - i * c.j) / mod << ")" << endl;
    return Complex((i * c.i + j * c.j) / mod, (j * c.i - i * c.j) / mod);
  }

  void prn() { cout << "(" << i << " + i" << j << ")" << endl; }
};

int main() {

  Complex c1(10, 10), c2(20, 20), c3;

  c3 = c1 - c2;
  cout << "c3: ";
  c3.prn();

  c3 = c1 * c2;
  cout << "c3: ";
  c3.prn();

  c3 = c1 / c2;
  cout << "c3: ";
  c3.prn();

  c3 = c1 / Complex(0, 0);

  c3 = c1 + c2;
  cout << "c3: ";
  c3.prn();

  c3 = c3 + c1 + c2 + c2;
  cout << "c3: ";
  c3.prn();
}
