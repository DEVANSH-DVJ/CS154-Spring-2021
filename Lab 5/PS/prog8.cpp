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
class C : public B {
 public:
	virtual void f(){cout << "C::f\n";}
         virtual void k() {cout << "C::k\n"; f(); }
};
int main (int argc, char *argv[]) {
 A *ap; 
 B *bp; 
 C *cp;

   cp = new C();
   bp=cp;
   ap=bp;
   ap->f(); ap->g();
}

