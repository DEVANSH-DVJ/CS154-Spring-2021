#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;

int dice() {
  // srand(time(0));
  return rand() % 6 + 1;
}

struct seq {
  int n;
  int *sequence;
};

void generateSequence(struct seq *s, int N) {
  s->n = N;
  s->sequence = new int[N];

  for (int i = 0; i < N; i++) {
    s->sequence[i] = dice();
  }
}

void calculateProbability(struct seq *s) {
  int face[7];
  for (int i = 1; i < 7; i++) {
    face[i] = 0;
  }

  for (int i = 0; i < s->n; i++) {
    face[s->sequence[i]]++;
  }

  for (int i = 1; i < 7; i++) {
    printf("%i: %f\n", i, double(face[i]) / double(s->n));
  }
}

int main(int argc, char *argv[]) {

  if (argc > 1) {
    struct seq *s = new struct seq();

    generateSequence(s, stoi(argv[1]));
    calculateProbability(s);
  }

  return 0;
}
