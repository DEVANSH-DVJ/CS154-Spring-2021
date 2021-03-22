/**
 * Author: Devansh Jain (190100044)
 * Lab 3 - Stack Implementation (Model 3)
 */

#include <iostream>

using namespace std;

// third solution: structure the body elements... neater and safer,,
// encapsulating elements in one structure second solution: allows two instaces
// of the abstraction in main
// first solution does not permit that..

struct stack {
  int S[100];   // S[45] is 46th element!
  int top = 0;  // current position in stack which is empty, position indicator
  int card = 0; // cardinality, no. of elements in the stack
};

void push(int elem, struct stack *s); // add an element on top of stack
int pop(struct stack *s);  // note the value at the top, remove the top and
                           // return the value
int card(struct stack *s); // cardinality, how many elements in stack

void push(int elem, struct stack *s) {
  if (s->top == 100) {
    cout << "Stack Overflow" << endl;
    return;
  }

  s->S[s->top] = elem;
  s->top++;
  s->card++;

  cout << elem << " added to the top of the stack" << endl;

  return;
};

int pop(struct stack *s) {
  if (s->top == 0) {
    cout << "Stack Underflow" << endl;
    return -1;
  }

  s->top--;
  s->card--;

  cout << s->S[s->top] << " removed from the top of the stack" << endl;

  return s->S[s->top];
}

int card(struct stack *s) { return s->card; }

//------------- section 3 ---- user of the abstraction ------

int main() { // is a user of the object, through its abstraction...
  struct stack s1, s2;
  int e;

  push(10, &s1);
  push(12, &s1);
  push(14, &s2);
  e = pop(&s1);
  cout << e << endl;
  e = pop(&s1);
  cout << e << endl;
  push(10, &s2);
  push(12, &s2);
  push(14, &s1);
  e = pop(&s2);
  cout << e << endl;
  e = pop(&s1);
  cout << e << endl;
  e = pop(&s1);

  return 0;
}
