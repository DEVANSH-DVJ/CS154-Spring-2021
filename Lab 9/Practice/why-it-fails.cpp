#include <iostream>
using namespace std;

// why is there a compile time error?!

int main() {

  bool a = true, b = true;

  // cout << a || b << endl; // Compile Time Error
  cout << (a || b) << endl; // Works fine

  return 0;
}
