#include <iostream>
using namespace std;

class A {
protected:
  int x;

public:
  A(int v) { x = v; }
  virtual void f() { cout << x << "A::f\n"; }
  virtual void g() { cout << x << "A::g\n"; }
};

class B {
protected:
  int x;

public:
  B(int v) { x = v; }
  virtual void g() { cout << x << "B::g\n"; }
  virtual void h() { cout << x << "B::h\n"; }
};

class C : public A, public B {
protected:
  int z;

public:
  C(int v) : B(v + 10), A(v + 100) { z = v; }
  virtual void f() {
    cout << A::x << ":" // We can access x in A using A::x
         << B::x << ":" // We can access x in B using B::x
         << z << "C::f\n";
  }
  virtual void k() {
    cout << A::x << ":" // We can access x in A using A::x
         << B::x << ":" // We can access x in B using B::x
         << z << "C::k\n";
  }
};

int main(int argc, char *argv[]) {
  A *ap;
  B *bp;
  C *cp;

  cp = new C(10);
  cp->f();
  cp->A::f(); // We can access f in A using A::f
  cp->A::g(); // We can access g in A using A::g
  cp->B::g(); // We can access g in B using B::g
  cp->h();
  cp->k();
  bp = cp;
  bp->g();
  bp->h();
  ap = cp;
  ap->f();
  ap->g();

  cout << "----------------------\n";

  A a(1);
  B b(2);
  C c(3);
  c.f();
  c.A::g(); // We can access g in A using A::g
  c.B::g(); // We can access g in B using B::g
  c.h();
  c.k();
  b.g();
  b.h();
  a.f();
  a.g();
  b = c;
  a = c;
  b.g();
  b.h();
  a.f();
  a.g();
}
