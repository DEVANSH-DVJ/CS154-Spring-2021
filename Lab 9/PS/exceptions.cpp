#include <iostream>
using namespace std;

class OutofBound {
 int e;
 public:
	OutofBound (int e) {
		this->e = e;
	}

	void msg() {
		switch(e) {
			case 0: cout << "array underflow access\n"; break;
			case 1: cout << "array overflow access\n"; break;
		}
	}

};

class Collection {

 int array[10];

  public:

	int & operator [] (int i) {

		if (i>=10) throw OutofBound(1);
		if (i<0) throw OutofBound(0);
		return (array[i]);
	}

	void prn() {
		for (int i=0; i<10; i++)
			cout << array[i] << " ";
		cout << endl; 
	}
};

main () {

 Collection c;

 for (int i=-5; i<15; i++)  {
	try {
		c[i]=i;
	} 

	catch (OutofBound e) {
		e.msg();
	}


 }
 c.prn();


}
