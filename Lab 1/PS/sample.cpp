#include <iostream>
using namespace std;

class Projector {
 int status;

 public:
	void switchOn(void);
	void switchOff(void);
	int getStatus(void);
};

void Projector::switchOn(void) {  status=1;}
void Projector::switchOff(void) {  status=0;}
int Projector::getStatus(void) {  return status;}


int main (int argc, char *argv[]) {

 int s;

 Projector *p = new Projector();
 p->switchOn();
 p->switchOn();
 p->switchOff();

 s= p->getStatus();

 cout << s << endl; 

}

