#include <iostream>
//#define NDEBUG  // uncomment to turn off Assertions

#include <cassert>
using namespace std;

int main() {

  int n;
  cin >> n;

  int a[n];

  for (int i = 0; i <= n; i++) {

    assert(i < n);
    assert(i > -1);

    a[i] = i;
  }
}
