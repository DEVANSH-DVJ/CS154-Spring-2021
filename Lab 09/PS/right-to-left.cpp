#include <iostream>
using namespace std;
class A {
 int id;
 public:
	A (int v) {id=v;}
	A &operator = (A &a) {
		cout << "executing " << id << "=" << a.id << endl;
		return *this;
	}
};
int main () {
 int a=1, b=2, c=3;
	a = (++b) = (c++);
 cout << a << b << c << endl;
 A a1(1), a2(2), a3(3);
	a1=a2=a3;
}
