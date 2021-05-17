/**
 * Author: Devansh Jain (190100044)
 * Lab 3 - 2 Input Logic Gates (using Abstract Classes and Virtual Functions)
 */

#include <iostream>

using namespace std;

/**
 * @class Gate
 * @brief Abstract Base class for all Logic Gates
 */
class Gate {
protected:
  bool store; // Output stored

public:
  /**
   * @fn fire
   * @param[in] i value of boolean input at Pin 1
   * @param[in] j value of boolean input at Pin 2
   * @return boolean output of the gate
   * @brief a pure virtual function needed to defined in derived classes
   */
  virtual bool fire(bool i, bool j) = 0;

  /**
   * @fn
   * @return returns the protected member variable store
   * @brief returns the stored value
   */
  bool getoutput();
};

/**
 * @class AndGate
 * @brief Derived from Abstract class Gate
 *        implements AND Gate
 */
class AndGate : public Gate {
public:
  bool fire(bool i, bool j);
};

/**
 * @class OrGate
 * @brief Derived from Abstract class Gate
 *        implements OR Gate
 */
class OrGate : public Gate {
public:
  bool fire(bool i, bool j);
};

/**
 * @class XorGate
 * @brief Derived from Abstract class Gate
 *        implements XOR Gate
 */
class XorGate : public Gate {
public:
  bool fire(bool i, bool j);
};

bool Gate::getoutput() { return store; }

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
