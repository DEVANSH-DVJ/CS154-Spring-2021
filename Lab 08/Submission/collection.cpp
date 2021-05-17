/**
 * Author: Devansh Jain (190100044)
 * Lab 8 - Collection - with bugs and assertions
 */

#include <cassert>
#include <iostream>

using namespace std;

/**
 * @class Collection
 * @brief It has bugs and assertions catch it
 */
class Collection {
  int *S;
  int cap, card;

public:
  Collection(int sz) {
    assert(sz >= 0); // max size of collection should be non-negative

    S = new int[sz];
    card = 0;

    assert(card == 0); // collection should be empty at start
    assert(cap == sz); // cap should be equal to max size of collection
  }

  void push_back(int elem) {
    assert(card < cap); // collection should not be full

    S[card] = elem;
    cout << elem << " added in Collection\n";
    card++;

    assert(card >= 0);   // cardinality should not negative
    assert(card <= cap); // cardinality should not have exceed full
  }

  int pop_back() {
    assert(card > 0); // collection should not be empty

    card--;
    cout << S[card] << " popped out of Collection\n";

    assert(card >= 0);   // cardinality should not negative
    assert(card <= cap); // cardinality should not have exceed full

    return S[card];
  }
};

int main() {

  Collection c1(-1);
  Collection c2(4);

  for (int i = 0; i < 5; i++)
    c2.push_back(i);

  for (int i = 0; i < 6; i++)
    c2.pop_back();

  return 0;
}
