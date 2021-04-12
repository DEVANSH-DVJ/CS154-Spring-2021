#include<iostream>
using namespace std;
class A {
  int x;
  public:
        A(int v) {x=v;}
	virtual void f() {cout << x << "A::f\n"; g(); }
	virtual void g() { cout << x << "A::g\n";}
};
class B : public A {
 int y;
 public:
        B(int v):A(v+10) {y=v;}
	virtual void f(){cout << y << "B::f\n";}
        virtual void g() {cout << y << "B::g\n";}
};
class C : public B {
 int z;
 public:
        C(int v):B(v+10) {z=v;}
	virtual void f(){cout << z << "C::f\n";}
         virtual void k() {f(); cout << z << "C::k\n"; f(); }
};
int main (int argc, char *argv[]) {
 A *ap; 
 B *bp; 
 C *cp;

   cp = new C(10);
   cp->f(); cp->g(); cp->k();
   bp = new B(100);
   bp->f(); bp->g(); 
   delete bp;
   bp=cp;
   bp->f(); bp->g();
   ap = new A(200);
   ap->f(); ap->g();
   delete ap;
   ap=bp;
   ap->f(); ap->g();
}

