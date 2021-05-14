/**
 * Author: Devansh Jain (190100044)
 * Lab 9 - Exceptions
 */

#include <iostream>
using namespace std;

class OutofBound {
  int e;

public:
  OutofBound(int e) { this->e = e; }

  void msg() {
    switch (e) {
    case 0:
      cout << "Array underflow access\n";
      break;
    case 1:
      cout << "Array overflow access\n";
      break;
    }
  }
};

class Collection {
  int array[10];

public:
  int &operator[](int i) {

    if (i >= 10)
      throw OutofBound(1);
    if (i < 0)
      throw OutofBound(0);
    return (array[i]);
  }

  void prn() {
    for (int i = 0; i < 10; i++)
      cout << array[i] << " ";
    cout << endl;
  }
};

int main() {

  Collection c;

  for (int i = -5; i < 15; i++) {
    try {
      c[i] = i;
    }

    catch (OutofBound e) {
      e.msg();
    }
  }

  c.prn(); // 0 1 2 3 4 5 6 7 8 9

  return 0;
}
