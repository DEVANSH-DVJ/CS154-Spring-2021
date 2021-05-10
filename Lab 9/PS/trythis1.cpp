#include <iostream>

using namespace std;

void f(int x, int y) {

 cout << x << " " << y << endl;
}

int main () {
int i=10;

 f(i, i++);

//i = 100;

 f(++i, i++);

cout << i << endl;

}
