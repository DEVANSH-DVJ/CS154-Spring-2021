#include <iostream>
using namespace std;
#include <cassert>
// A program which is not correct
class Collection {
int *S;
int cap, card;

  public:
	Collection(int sz) {
		S = new int [sz];
		card=0;
  //... add assertion(s)...
	}

	void push_back(int elem) {
  //... add assertion(s)...


  //... add logic

  //... add assertion(s)...

	}

	int pop_back() {
  //... add assertion(s)...


  //... add logic

  //... add assertion(s)...


	}
};
int main () {

   // add code that tests the class above and fails it, which gets caught by assertions

}

