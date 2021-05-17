#include <iostream>
using namespace std;
 struct projector {
   int status;
  };

void switchOn(struct projector *p) {  p->status=1;}
void switchOff(struct projector *p) {  p->status=0;}
int getStatus(struct projector *p) {  return p->status;}


int main (int argc, char *argv[]) {

 int s;

 struct projector *p = new struct projector();
 switchOn(p);
 switchOn(p);
 switchOff(p);

 s = getStatus(p);

 cout << s << endl; 

}

