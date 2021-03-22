/**
 * Author: Devansh Jain (190100044)
 * Lab 3 - Vending Machine
 */

#include <iostream>

using namespace std;

/**
 * @class VendingMachine
 * @brief Behaves as a vending machine to buy drinks
 */
class VendingMachine {
  int n;                 // Number of drinks
  int *price, *quantity; // Prices and Quantities of all drinks
  int in;                // Coins inserted

public:
  /**
   * @ctor VendingMachine
   * @param[in] n number of drinks
   * @param[in] price array of price of each drink
   * @param[in] quantity array of quantity of each drink
   * @brief initializes the price and quantity arrays and stores the values
   *        initializes in as 0
   */
  VendingMachine(int n, int price[], int quantity[]);

  /**
   * @dtor VendingMachine
   * @brief Deletes dynamically created arrays price and quantity
   */
  ~VendingMachine();

  /**
   * @fn insertcoin
   * @param[in] val value of coin inserted
   * @brief inserts coin of certain value and adds in
   */
  void insertcoin(int val);

  /**
   * @fn selectdrink
   * @param[in] drinkid ID of the drink
   * @param[out] change change returned
   * @return true if drink can be returned
   * @brief checks whether the drink can be bought using the coins inserted
   *        and accordingly returns change
   */
  bool selectdrink(int drinkid, int &change);
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
    cout << "Drink " << drinkid << " costs more than value of coins entered."
         << endl;
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
    cout << "Bought drink 2, change returned: " << change << endl;
  } else {
    cout << "Couldn't buy drink 2. change returned: " << change << endl;
  }

  cout << endl;
  machine.insertcoin(10);
  machine.insertcoin(5);
  if (machine.selectdrink(2, change)) {
    cout << "Bought drink 2, change returned: " << change << endl;
  } else {
    cout << "Couldn't buy drink 2. change returned: " << change << endl;
  }

  cout << endl;
  machine.insertcoin(10);
  machine.insertcoin(5);
  if (machine.selectdrink(4, change)) {
    cout << "Bought drink 4, change returned: " << change << endl;
  } else {
    cout << "Couldn't buy drink 4. change returned: " << change << endl;
  }

  cout << endl;
  machine.insertcoin(10);
  machine.insertcoin(5);
  machine.insertcoin(1);
  machine.insertcoin(1);
  if (machine.selectdrink(2, change)) {
    cout << "Bought drink 2, change returned: " << change << endl;
  } else {
    cout << "Couldn't buy drink 2. change returned: " << change << endl;
  }

  cout << endl;
  machine.insertcoin(10);
  if (machine.selectdrink(1, change)) {
    cout << "Bought drink 1, change returned: " << change << endl;
  } else {
    cout << "Couldn't buy drink 1. change returned: " << change << endl;
  }

  cout << endl;
  machine.insertcoin(10);
  if (machine.selectdrink(1, change)) {
    cout << "Bought drink 1, change returned: " << change << endl;
  } else {
    cout << "Couldn't buy drink 1. change returned: " << change << endl;
  }

  cout << endl;
  machine.insertcoin(10);
  if (machine.selectdrink(6, change)) {
    cout << "Bought drink 6, change returned: " << change << endl;
  } else {
    cout << "Couldn't buy drink 6. change returned: " << change << endl;
  }

  cout << endl;
  machine.insertcoin(10);
  if (machine.selectdrink(1, change)) {
    cout << "Bought drink 1, change returned: " << change << endl;
  } else {
    cout << "Couldn't buy drink 1. change returned: " << change << endl;
  }

  return 0;
}
