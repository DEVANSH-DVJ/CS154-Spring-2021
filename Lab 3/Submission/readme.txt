Models (model_*.cpp)
The abstraction was already provided. Had to fill in the code for functions.
Observations:
model_1.cpp - Implemented one stack which was global with all members separately accessible to the main.
model_2.cpp - Implemented two stacks which was global with all members separately accessible to the main.
model_3.cpp - Implemented stack as a structure with local objects created in main whose variables were accessible in main.
model_4.cpp - Implemented Stack as a class with local objects created in main whose variables were not accessible in main.

Vending Machine (vendingmachine.cpp)
Used Object Oriented Programming using Classes.
Designed one class VendingMachine which can take in coins and can return the drink asked for if feasible.
It has private member variables and public member functions.
It has a constructor to initialize the price and quantity for each drink.
It has a destructor to clear out dynamically alloted space to arrays price and quantity.
Testing presented in main.

2 Input Logic Gates (2pinGate.cpp)
Using Object Oriented Programming using Abstract Classes and Virtual Functions.
Created a base class Gate which has a proper function getoutput() to return the stored value.
This is common across all logic gates, so need not be defined again and again.
Gate also has a pure virtual function fire(bool, bool) to calculate and return the output of the gate.
This varies across gates but has a common declaration across all and is necessary, so is declared as a pure virtual function.
There are three derived classes AndGate, OrGate and XorGate which implement AND Gate, OR Gate and XOR Gate respectively.
Testing presented in main.
