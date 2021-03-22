
// code by Prof. R.K.Joshi, CSE, IIT Bombay
// part of CS 152/154 2021

#include <iostream>
using namespace std;

// second solution: allows two instaces of the abstraction in main
// first solution does not permit that..

//--------------- section 1 ---- interface of the abstraction
// declarations give us the abstraction (interface)

void push(int elem, int *S, int *top,
          int *card);                 // add an element on top of stack
int pop(int *S, int *top, int *card); // note the value at the top, remove the
                                      // top and return the value
int card(int *S);                     // cardinality, how many elements in stack

//-----------section 2 --- implementation of the abstraction--
// definitions give us the implementation of the abstraction (bodies)

int S1[100];   // S[45] is 46th element!
int top1 = 0;  // current position in stack which is empty, position indicator
int card1 = 0; // cardinality, no. of elements in the stack

int S2[100];   // S[45] is 46th element!
int top2 = 0;  // current position in stack which is empty, position indicator
int card2 = 0; // cardinality, no. of elements in the stack

void push(int elem, int *S, int *top, int *card) {
  if (*top == 100) {
    cout << "Stack Overflow" << endl;
    return;
  }
  S[*top] = elem;
  cout << elem << " added to the top of the stack" << endl;
  ++*top;
  ++*card;
  return;
};

int pop(int *S, int *top, int *card) {
  if (*top == 0) {
    cout << "Stack Underflow" << endl;
    return -1;
  }
  --*top;
  --*card;
  cout << S[*top] << " removed from the top of the stack" << endl;
  return S[*top];
}

int card(int *S) {
  if (S == S1)
    return card1;
  else
    return card2;
}

//------------- section 3 ---- user of the abstraction ------

int main() { // is a user of the object, through its abstraction...
  int e;
  push(10, S1, &top1, &card1);
  push(12, S1, &top1, &card1);
  push(14, S2, &top2, &card2);
  e = pop(S1, &top1, &card1);
  cout << e << endl;
  e = pop(S1, &top1, &card1);
  cout << e << endl;

  push(10, S2, &top2, &card2);
  push(12, S2, &top2, &card2);
  push(14, S1, &top1, &card1);
  e = pop(S2, &top2, &card2);
  cout << e << endl;
  e = pop(S1, &top1, &card1);
  cout << e << endl;
}
