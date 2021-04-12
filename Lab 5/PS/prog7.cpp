#include<iostream>
using namespace std;
class A {
  public:
	virtual void f() {cout<<"A::f\n"; g(); }
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
         virtual void k() {cout << "C::k\n"; f(); }
};
int main (int argc, char *argv[]) {
 A *ap; 
 B *bp; 
 C *cp;
 A a;
 B b; 
   ap = new A();
   ap->f(); ap->g();
   delete ap;
   cp = new C();
   cp->f(); cp->g();  cp->k();
   ap = cp;
   ap->f(); ap->g(); 
   ap = bp;
   ap->f(); ap->g(); 
}

