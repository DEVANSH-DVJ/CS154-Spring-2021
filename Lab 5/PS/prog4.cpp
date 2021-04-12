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
        virtual void g() {cout << "B:g\n";}
};
int main (int argc, char *argv[]) {
 A *ap; 
 B *bp; 
 A a;
 B b; 

   ap = new A();  
   bp = new B();
	ap->f(); 
        ap->g();   
        a.f();
        a.g();
        b.f();
        b.g();
}
