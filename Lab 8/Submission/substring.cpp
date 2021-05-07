/**
 * Author: Devansh Jain (190100044)
 * Lab 8 - Subtring Matching - with bugs and assertions
 */

#include <cassert>
#include <iostream>
#include <string>

using namespace std;

int find(string str, string sub) {
  int L = str.length(), l = sub.length();

  assert(l > 0);  // substring should have a positive length
  assert(L >= l); // string should not be shorter than substring

  int i = 0;
  for (i = 0; i < L - l; i++) {
    bool found = true;
    for (int j = i; j < l; j++) {
      if (str[i + j] != sub[j]) {
        found = false;
        break;
      }
    }
    if (found)
      return i + 1; // index at which substring starts
  }

  assert(i == L - l); // only return -1 if all starting points checked

  return -1; // No substring found
}

int main() {

  string str = "Computer Science and Engineering";

  cout << find(str, "B. Tech., Indian Institute of Technology, Bombay") << endl;
  cout << find(str, "") << endl;

  return 0;
}
