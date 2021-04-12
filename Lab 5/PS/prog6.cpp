#include<iostream>
using namespace std;
class A {
  public:
	virtual void f() {cout<<"A::f\n";}
	virtual void g() { cout << "A::g\n";}
};
class B : public A {
 public:
	virtual void f(){cout << "B::f\n";}
        virtual void g() {cout << "B::g\n";}
};
class C : public A {
 public:
	virtual void f(){cout << "C::f\n";}
         virtual void k() {cout << "C::k\n";}
};
int main (int argc, char *argv[]) {
 A *ap; 
 B *bp; 
 C *cp;
 A a;
 B b; 
   ap = new A();  
   bp = new B();
   cp = new C();
   
  ap->f(); ap->g(); 
 // ap->k();  not permitted since k() is not included in variable type ap
  bp->f(); bp->g();
  cp->f(); cp->g();   
  ap = bp; // permitted by inheritance rule (type-subtype):
			// in assignment, check variable type
		// LHS type: T, RHS type: S
		// T=S if S is used as T it will work, or S is subclass of T
  ap->f(); ap->g(); 
  ap = cp;
  ap->f(); ap->g(); 
 // ap->k();   not permitted! since ap is of type A


}
