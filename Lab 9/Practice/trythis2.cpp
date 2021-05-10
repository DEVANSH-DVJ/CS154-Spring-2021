#include <iostream>

using namespace std;

void f(int x, int y, int z) { cout << x << " " << y << " " << z << endl; }

int main() {
  int i = 10;

  f(i, i++, ++i);

  // i = 100;

  f(++i, i++, ++i);

  cout << i << endl;
}
