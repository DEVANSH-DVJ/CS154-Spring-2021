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
int main (int argc, char *argv[]) {
 A *ap; 
 B *bp; 
 A a(100);
 B b(200);
   a.f(); a.g();
   b.f(); b.g();
   a = b;
   a.f(); a.g();
}

