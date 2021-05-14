// program by Prof. R.K.Joshi
// for CS152, IIT Bombay

#include <iostream>
using namespace std;

// observe definition of our own operator for use with objects,
// which means for use with values which are not primitive data types
// note the associativity from right to left

class Collection {
  int *array, card, maxsize; // storage and cardinality
public:
  Collection(int sz) {
    array = new int[sz];
    card = 0;
    maxsize = sz;
  }

  Collection &operator<<(int elem) {
    if (card < maxsize)
      array[card++] = elem;
    else
      cout << "Collection is full" << endl;
    return *this;
  }

  Collection &operator<<(Collection c) {
    for (int i = 0; i < c.card; i++) {
      if (card == maxsize) {
        cout << "Collection is full" << endl;
        return *this;
      }
      *this << c.array[i];
    }
    return *this;
  }

  Collection &operator>>(int &a) {
    if (card > 0)
      a = array[--card];
    else
      cout << "Collection is empty" << endl;
    return *this;
  }

  void prn() {
    if (card == 0) {
      cout << "Collection is empty" << endl;
      return;
    }
    cout << "Collection has " << card << " elements: ";
    for (int i = 0; i < card; i++)
      cout << array[i] << " ";
    cout << endl;
  }
};

int main() {

  Collection c1(3);
  c1 << 1;
  c1 << 2;
  c1 << 3;
  c1 << 4;  // Output line 1
  c1 << 5;  // Output line 2
  c1.prn(); // Output line 3

  Collection c2(3);
  c2 << 1 << 2 << 3;
  c2.prn(); // Output line 4

  int a, b;
  c2 >> a >> b;
  c2.prn();                                            // Output line 5
  cout << "Popped out: " << a << " and " << b << endl; // Output line 6

  Collection c3(10);
  c3.prn(); // Output line 7
  c3 << c2 << c1 << c2 << c1;
  c3.prn(); // Output line 8

  return 0;
}
