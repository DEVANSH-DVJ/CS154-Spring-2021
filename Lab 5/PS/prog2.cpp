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
 B b; // not an error because all member functions have been defined by the
	// the time you come to B
       // virtual does not mean that class is abstract
     // = 0 meaans class is abstract
  // virtual means dynamic binding is possible

	ap->f(); // invalid access, no object assigned yet!  // runtime error only!
        ap->g();  // ---"---   
      //  b->f(); // b is not a pointer, use . operator (dot operator) // syntax error
       // b->g(); // --"---
}
