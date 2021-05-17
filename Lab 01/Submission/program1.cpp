#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;

int dice() {
  // srand(time(0));
  return rand() % 6 + 1;
}

class Seq {
  int n;
  int *sequence;

public:
  Seq(int n);
  void generateSequence();
  void calculateProbability();
};

Seq::Seq(int n) {
  this->n = n;
  sequence = new int[n];
}

void Seq::generateSequence() {
  for (int i = 0; i < n; i++) {
    sequence[i] = dice();
  }
}

void Seq::calculateProbability() {
  int face[7];
  for (int i = 1; i < 7; i++) {
    face[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    face[sequence[i]]++;
  }

  for (int i = 1; i < 7; i++) {
    cout << i << ": " << double(face[i]) / double(n) << endl;
  }
}

int main(int argc, char *argv[]) {

  if (argc > 1) {
    Seq *s = new Seq(stoi(argv[1]));

    s->generateSequence();
    s->calculateProbability();
  }

  return 0;
}
