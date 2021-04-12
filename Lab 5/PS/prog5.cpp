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
 //---------------

 cout << "-----------------\n";

   ap = bp;   // LHS variable type A*,  RHS variable type B*, compatible due to
      // inheriatance, which defines is_a relation.. so assignment is allowed
   a = b; 
	ap->f();  // variable type: A*, call permitted, object type: B*, call goes into B
        ap->g();   
        a.f();
        a.g();
        b.f();
        b.g();
}
