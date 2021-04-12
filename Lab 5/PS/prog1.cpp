#include<iostream>
using namespace std;
class A {
  public:
	virtual void f()=0;
	virtual void g() { cout << "A::g\n";}
};
class B : public A {
 public:
	virtual void f(){cout << "B::f\n";}
        virtual void g() {cout << "B:g\n";}
};
int main (int argc, char *argv[]) {
 A *ap; 
 B *bp; 
 A a;   // error!
 B b;
}
