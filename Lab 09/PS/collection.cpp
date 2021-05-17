//program by Prof. R.K.Joshi
//for CS152, IIT Bombay

#include <iostream>
using namespace std;

//observe definition of our own operator for use with objects,
// which means for use with values which are not primitive data types
// note the associativity from right to left

class Collection {
 int *array, card, maxsize; // storage and cardinality
 public:
	 Collection (int sz) {
		array = new int [sz];	
		card = 0;
		maxsize = sz;
	 }

	 Collection &operator << (int elem) {
		if (card < maxsize) array [card++] = elem;
		return *this;
	 }

	 void prn() { 
		for (int i=0; i<maxsize; i++)
			cout << array[i] << " ";
		cout << endl;
	}
};

int main () {

	Collection c1 (3);

		c1 << 1;
		c1 << 2;
		c1 << 3;
		c1 << 4;
		c1 << 5;
		c1.prn();

	Collection c2(3);

		c2 << 1 << 2 << 3;
		c2.prn();

}
