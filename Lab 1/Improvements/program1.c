/**
 * Author: Devansh Jain (190100044)
 * Lab 1 - Progam 1 - Procedural:
 * A program that counts the probability of every possibility
 * of throwing a 6 faced dice, N times. [use random number generator]
 * Take N as command line parameter to your program
 */

#include <stdio.h>  // IO library
#include <stdlib.h> // Standard library
#include <time.h>   // time() - for random seed generation

/**
 * @fn dice
 * @brief chooses and returns a random number from {1,2,3,4,5,6}
 */
int dice() { return rand() % 6 + 1; }

/**
 * @struct seq
 * @brief stores the sequence and its length
 */
struct seq {
  int n;
  int *sequence;
};

/**
 * @fn genseq
 * @param[out] s the generated sequence
 * @param[in] N length of the sequence to be generated
 * @brief allocates space for the sequence
 *        and fills it with random numbers from {1,2,3,4,5,6}
 */
void genseq(struct seq *s, int N) {
  s->n = N;
  s->sequence = (int *)malloc(N * sizeof(int));

  for (int i = 0; i < N; i++) {
    s->sequence[i] = dice();
  }
}

/**
 * @fn calprob
 * @param[in] s sequence of random numbers from {1,2,3,4,5,6}
 * @brief calculates probability of each of the faces
 */
void calprob(struct seq *s) {
  int face[7];
  for (int i = 1; i < 7; i++) {
    face[i] = 0;
  }

  for (int i = 0; i < s->n; i++) {
    face[s->sequence[i]]++;
  }

  for (int i = 1; i < 7; i++) {
    printf("%i: %f\n", i, ((double)face[i]) / ((double)s->n));
  }
}

int main(int argc, char *argv[]) {

  // Check the number of arguments
  if (argc != 2) {
    printf("Usage: %s <number of rolls>\n", argv[0]);
    exit(1);
  }

  // Set random seed
  srand(time(0));

  // Get N from command line argument
  int N = atoi(argv[1]);

  // Do the experiment and output the result
  struct seq s;
  genseq(&s, N);
  calprob(&s);

  return 0;
}
