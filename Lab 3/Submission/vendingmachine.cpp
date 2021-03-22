#include <iostream>

using namespace std;

class VendingMachine {
  int n;
  int *price, *quantity;
  int in;

public:
  VendingMachine(int n, int price[], int quantity[]);
  ~VendingMachine();
  void insertcoin(int val);
  bool selectdrink(int drinkid, int &change); // returns true if successful
};

VendingMachine::VendingMachine(int n, int price[], int quantity[]) {
  this->n = n;
  this->price = new int[n];
  this->quantity = new int[n];
  for (int i = 0; i < n; i++) {
    this->price[i] = price[i];
    this->quantity[i] = quantity[i];
  }
  this->in = 0;
}

VendingMachine::~VendingMachine() { delete price, quantity; }

void VendingMachine::insertcoin(int val) {
  this->in += val;
  return;
}

bool VendingMachine::selectdrink(int drinkid, int &change) {
  if (drinkid >= n || drinkid < 0) {
    change = this->in;
    this->in = 0;
    cout << "Invalid Drink ID " << drinkid << "." << endl;
    return false;
  }
  if (quantity[drinkid] <= 0) {
    change = this->in;
    this->in = 0;
    cout << "Drink " << drinkid << " not available." << endl;
    return false;
  }
  if (price[drinkid] > this->in) {
    change = this->in;
    this->in = 0;
    cout << "Drink " << drinkid << " costs more than value entered." << endl;
    return false;
  }
  change = this->in - price[drinkid];
  this->in = 0;
  return true;
}

int main(int argc, char *argv[]) {
  int price[5] = {5, 10, 17, 2, 12};
  int quantity[5] = {10, 2, 5, 10, 3};

  VendingMachine machine(5, price, quantity);
  int change;

  cout << endl;
  machine.insertcoin(10);
  if (machine.selectdrink(2, change)) {
    cout << "Drink 2 returned, Change: " << change << endl;
  } else {
    cout << "Drink 2 not returned, Change: " << change << endl;
  }

  cout << endl;
  machine.insertcoin(10);
  machine.insertcoin(5);
  if (machine.selectdrink(2, change)) {
    cout << "Drink 2 returned, Change: " << change << endl;
  } else {
    cout << "Drink 2 not returned, Change: " << change << endl;
  }

  cout << endl;
  machine.insertcoin(10);
  machine.insertcoin(5);
  if (machine.selectdrink(4, change)) {
    cout << "Drink 4 returned, Change: " << change << endl;
  } else {
    cout << "Drink 4 not returned, Change: " << change << endl;
  }

  cout << endl;
  machine.insertcoin(10);
  machine.insertcoin(5);
  machine.insertcoin(1);
  machine.insertcoin(1);
  if (machine.selectdrink(2, change)) {
    cout << "Drink 2 returned, Change: " << change << endl;
  } else {
    cout << "Drink 2 not returned, Change: " << change << endl;
  }

  cout << endl;
  machine.insertcoin(10);
  if (machine.selectdrink(1, change)) {
    cout << "Drink 1 returned, Change: " << change << endl;
  } else {
    cout << "Drink 1 not returned, Change: " << change << endl;
  }

  cout << endl;
  machine.insertcoin(10);
  if (machine.selectdrink(1, change)) {
    cout << "Drink 1 returned, Change: " << change << endl;
  } else {
    cout << "Drink 1 not returned, Change: " << change << endl;
  }

  cout << endl;
  machine.insertcoin(10);
  if (machine.selectdrink(6, change)) {
    cout << "Drink 6 returned, Change: " << change << endl;
  } else {
    cout << "Drink 6 not returned, Change: " << change << endl;
  }

  cout << endl;
  machine.insertcoin(10);
  if (machine.selectdrink(1, change)) {
    cout << "Drink 1 returned, Change: " << change << endl;
  } else {
    cout << "Drink 1 not returned, Change: " << change << endl;
  }

  return 0;
}
