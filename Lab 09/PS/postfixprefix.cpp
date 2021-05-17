// Program by Prof. R. K. Joshi
// for CS 152
// unary operator overloading: the ++ operator

#include <iostream>
using namespace std;

class A {

    int v;
	public:
		A(int x) { v = x;}
		void operator ++() {
			cout << "prefix operator called \n";
		}
		void operator ++(int) {
			cout << "postfix operator called \n";
		}

};

int main () {

 A a(10);
	++a;
	a++;
}
