/**
 * Author: Devansh Jain (190100044)
 * Lab 8 - String to Integer - with bugs and assertions
 */

#include <cassert>
#include <iostream>
#include <string>

using namespace std;

int str2int(string s) {
  int res = 0, i = 0, len = s.length();

  assert(len <= 9); // string should be compatible to size of int

  while (i != len) {
    assert(i < len);                    // i should not exceed length of string
    assert(s[i] >= '0' && s[i] <= '9'); // string characters must be a digit
    res = 10 * res + s[i] - '0';
    ++i;
  }

  assert(i == len); // should go thru all characters in the string

  return res;
};

int main() {

  cout << str2int("-4") << endl;

  cout << str2int("34t45") << endl;

  cout << str2int("1248664830475668493") << endl;

  return 0;
}
