/**
 * Author: Devansh Jain (190100044)
 * Lab 9 - Collection - cascading/nesting of operators and overloading
 */

#include <iostream>
using namespace std;

/**
 * @class Collection
 * @brief stack like collection of integers
 */
class Collection {
  int *array, card, maxsize; // storage, cardinality, maximum cardinality

public:
  /**
   * @fn Collection
   * @param[in] sz maximum size of stack
   * @brief constructor of Collection
   *        initializes the array
   */
  Collection(int sz) {
    array = new int[sz];
    card = 0;
    maxsize = sz;
  }

  /**
   * @fn operator<<
   * @param[in] elem element to be added
   * @return updated pointer to the object
   * @brief add element on top of stack is not full
   */
  Collection &operator<<(int elem) {
    if (card < maxsize)
      array[card++] = elem;
    else
      cout << "Collection is full" << endl;
    return *this;
  }

  /**
   * @fn operator<<
   * @param[in] c collection to be added
   * @return updated pointer to the object
   * @brief add elements of c on top of stack is not full
   */
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

  /**
   * @fn operator>>
   * @param[out] a element popped out
   * @return updated pointer to the object
   * @brief pop element on top of stack is not empty
   */
  Collection &operator>>(int &a) {
    if (card > 0)
      a = array[--card];
    else
      cout << "Collection is empty" << endl;
    return *this;
  }

  /**
   * @fn prn
   * @brief print the collection
   */
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
  c1 << 4;  // Collection is full
  c1 << 5;  // Collection is full
  c1.prn(); // Collection has 3 elements: 1 2 3

  Collection c2(3);
  c2 << 1 << 2 << 3;
  c2.prn(); // Collection has 3 elements: 1 2 3

  int a, b;
  c2 >> a >> b;
  c2.prn(); // Collection has 1 elements: 1
  cout << "Popped out: " << a << " and " << b << endl; // Popped out: 3 and 2

  Collection c3(10);
  c3.prn(); // Collection is empty
  c3 << c2 << c1 << c2 << c1;
  c3.prn(); // Collection has 8 elements: 1 1 2 3 1 1 2 3

  return 0;
}
