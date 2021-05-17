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
  virtual void f() { cout << z << "C::f\n"; }
  virtual void k() { cout << x << z << "C::k\n"; }
};

int main(int argc, char *argv[]) {
  A *ap;
  B *bp;
  C *cp;

  cp = new C(10);
  cp->f();
  cp->g();
  cp->h();
  cp->k();
  bp = cp;
  bp->g();
  bp->h();
  ap = cp;
  ap->f();
  ap->g();
}
