#include <iostream>

using namespace std;

class Gate {
protected:
  bool store;

public:
  virtual bool fire(bool i, bool j) = 0;
  bool getoutput();
};

bool Gate::getoutput() { return store; }

class AndGate : public Gate {
public:
  bool fire(bool i, bool j);
};

class OrGate : public Gate {
public:
  bool fire(bool i, bool j);
};

class XorGate : public Gate {
public:
  bool fire(bool i, bool j);
};

bool AndGate::fire(bool i, bool j) {
  store = i & j;
  return store;
}

bool OrGate::fire(bool i, bool j) {
  store = i | j;
  return store;
}

bool XorGate::fire(bool i, bool j) {
  store = i ^ j;
  return store;
}

int main(int argc, char *argv[]) {
  AndGate gate1;
  cout << "AND Gate" << endl;
  cout << gate1.fire(false, false) << gate1.getoutput() << endl;
  cout << gate1.fire(false, true) << gate1.getoutput() << endl;
  cout << gate1.fire(true, false) << gate1.getoutput() << endl;
  cout << gate1.fire(true, true) << gate1.getoutput() << endl;
  cout << endl;

  OrGate gate2;
  cout << "OR Gate" << endl;
  cout << gate2.fire(false, false) << gate2.getoutput() << endl;
  cout << gate2.fire(false, true) << gate2.getoutput() << endl;
  cout << gate2.fire(true, false) << gate2.getoutput() << endl;
  cout << gate2.fire(true, true) << gate2.getoutput() << endl;
  cout << endl;

  XorGate gate3;
  cout << "XOR Gate" << endl;
  cout << gate3.fire(false, false) << gate3.getoutput() << endl;
  cout << gate3.fire(false, true) << gate3.getoutput() << endl;
  cout << gate3.fire(true, false) << gate3.getoutput() << endl;
  cout << gate3.fire(true, true) << gate3.getoutput() << endl;
  cout << endl;

  return 0;
}
