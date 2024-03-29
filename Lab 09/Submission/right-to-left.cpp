/**
 * Author: Devansh Jain (190100044)
 * Lab 9 - Right to Left evaluation
 */

#include <iostream>
using namespace std;

class A {
  int id;

public:
  A(int v) { id = v; }
  A &operator=(A &a) {
    cout << "Executing " << id << "=" << a.id << endl;
    return *this;
  }
};

int main() {

  int a = 1, b = 2, c = 3;
  a = (++b) = (c++);
  cout << a << " " << b << " " << c << endl; // 3 3 4

  A a1(1), a2(2), a3(3);
  a2 = a3; // Executing 2=3
  a1 = a2; // Executing 1=2
  a3 = a1 = a3 = a2;
  // Executing 3=2
  // Executing 1=3
  // Executing 3=1

  return 0;
}
