/**
 * Author: Devansh Jain (190100044)
 * Lab 7 - Structured Code
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

void check(Gate *gate) {
  cout << gate->fire(false, false) << gate->getoutput() << endl;
  cout << gate->fire(false, true) << gate->getoutput() << endl;
  cout << gate->fire(true, false) << gate->getoutput() << endl;
  cout << gate->fire(true, true) << gate->getoutput() << endl;
  cout << endl;
}

int main(int argc, char *argv[]) {

  Gate *gate;

  gate = new AndGate();
  cout << "AND Gate" << endl;
  check(gate);

  gate = new OrGate();
  cout << "OR Gate" << endl;
  check(gate);

  gate = new XorGate();
  cout << "XOR Gate" << endl;
  check(gate);

  return 0;
}
