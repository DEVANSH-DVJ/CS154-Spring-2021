#include <iostream>
using namespace std;


int p=1;

int f(int i) { p=p+i; return p; }

int main () {

 cout << f(p) << f(p) << f(p) << f(++p) << endl;


}
