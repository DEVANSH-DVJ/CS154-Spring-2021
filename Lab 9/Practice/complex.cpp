/**
 * Author: Devansh Jain (190100044)
 * Lab 9 - Complex - cascading/nesting of operators
 */

#include <iostream>
using namespace std;

/**
 * @class Complex
 * @brief representation of complex numbers
 */
class Complex {
  float i, j; // coefficient of real and imaginary part

public:
  /**
   * @fn Complex
   * @brief constructor of Complex
   *        initializes to (0 + i0)
   */
  Complex() : Complex(0, 0) {}

  /**
   * @fn Complex
   * @param[in] x coefficient of real part
   * @param[in] y coefficient of complex part
   * @brief constructor of Complex
   *        initializes to (x + iy)
   */
  Complex(float x, float y) {
    i = x;
    j = y;
  }

  /**
   * @fn operator+
   * @param[in] c second operand
   * @return new complex number after operation
   * @brief adds two complex numbers
   */
  Complex operator+(Complex c) {
    cout << "(" << i << " + i" << j << ")"
         << " + "
         << "(" << c.i << " + i" << c.j << ")"
         << " = "
         << "(" << i + c.i << " + i" << j + c.j << ")" << endl;
    return Complex(i + c.i, j + c.j);
  }

  /**
   * @fn operator-
   * @param[in] c second operand
   * @return new complex number after operation
   * @brief subtracts two complex numbers
   */
  Complex operator-(Complex c) {
    cout << "(" << i << " + i" << j << ")"
         << " - "
         << "(" << c.i << " + i" << c.j << ")"
         << " = "
         << "(" << i - c.i << " + i" << j - c.j << ")" << endl;
    return Complex(i - c.i, j - c.j);
  }

  /**
   * @fn operator*
   * @param[in] c second operand
   * @return new complex number after operation
   * @brief multiplies two complex numbers
   */
  Complex operator*(Complex c) {
    cout << "(" << i << " + i" << j << ")"
         << " * "
         << "(" << c.i << " + i" << c.j << ")"
         << " = "
         << "(" << i * c.i - j * c.j << " + i" << i * c.j + j * c.i << ")"
         << endl;
    return Complex(i * c.i - j * c.j, i * c.j + j * c.i);
  }

  /**
   * @fn operator/
   * @param[in] c second operand
   * @return new complex number after operation
   * @brief divides two complex numbers
   */
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

  /**
   * @fn prn
   * @brief print the complex number
   */
  void prn() {
    cout << "(" << i << " + i" << j << ")" << endl;
  }
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
