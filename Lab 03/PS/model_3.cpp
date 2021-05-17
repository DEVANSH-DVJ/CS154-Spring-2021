
//code by Prof. R.K.Joshi, CSE, IIT Bombay
//part of CS 152/154 2021


#include <iostream>
using namespace std;

//third solution: structure the body elements... neater and safer,, encapsulating elements in one structure
//second solution: allows two instaces of the abstraction in main
// first solution does not permit that..


struct Stack {
int S[100]; // S[45] is 46th element!
int top=0; // current position in stack which is empty, position indicator
int card=0; // cardinality, no. of elements in the stack
}

 void push (int elem) ;// add an element on top of stack
 int pop ();  // note the value at the top, remove the top and return the value 
 int card(); // cardinality, how many elements in stack 



void push(int elem, struct stack *) {

            
};


//------------- section 3 ---- user of the abstraction ------

int main () { // is a user of the object, through its abstraction... 

struct stack s1, s2;

  push (10,&s1);
  push(12,&s1);
  push(14,&s1);
  e=pop(&s1);
  cout << e << endl;
  e=pop(&s1);
  cout << e << endl;

  push (10,&s1);
  push(12,&s1);
  push(14,&s1);
  e=pop(&s1);
  cout << e << endl;
  e=pop(&s1);
  cout << e << endl;


}
