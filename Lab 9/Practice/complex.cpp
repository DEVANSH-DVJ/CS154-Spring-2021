/**
 * Author: Devansh Jain (190100044)
 * Lab 9 - Complex - cascading/nesting of operators
 */

#include <iostream>
using namespace std;

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
  c3.prn(); // (-10 + i-10)

  c3 = c1 * c2;
  cout << "c3: ";
  c3.prn(); // (0 + i400)

  c3 = c1 / c2;
  cout << "c3: ";
  c3.prn(); // (0.5 + i0)

  c3 = c1 / Complex(0, 0); // Can't divide by 0

  c3 = c1 + c2;
  cout << "c3: ";
  c3.prn(); // (30 + i30)

  c3 = c3 + c1 + c2 + c2;
  cout << "c3: ";
  c3.prn(); // (80 + i80)

  return 0;
}
