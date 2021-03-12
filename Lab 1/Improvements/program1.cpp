/**
 * Author: Devansh Jain (190100044)
 * Lab 1 - Progam 1 - Object Oriented:
 * A program that counts the probability of every possibility
 * of throwing a 6 faced dice, N times. [use random number generator]
 * Take N as command line parameter to your program
 */

#include <iostream>

using namespace std;

/**
 * @fn dice
 * @brief chooses and returns a random number from {1,2,3,4,5,6}
 */
int dice() { return rand() % 6 + 1; }

/**
 * @class Seq
 * @brief stores the sequence and its length
 */
class Seq {
private:
  int n;
  int *sequence;

public:
  /**
   * @ctor Seq
   * @param[in] n length of the sequence
   * @brief allocates space for the sequence
   */
  Seq(int n);

  /**
   * @fn genseq
   * @brief fills the sequence with random numbers from {1,2,3,4,5,6}
   */
  void genseq();

  /**
   * @fn calprob
   * @brief calculates probability of each of the faces
   */
  void calprob();
};

Seq::Seq(int n) {
  this->n = n;
  sequence = new int[n];
}

void Seq::genseq() {
  for (int i = 0; i < n; i++) {
    sequence[i] = dice();
  }
}

void Seq::calprob() {
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

  // Check the number of arguments
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " <number of rolls>\n";
    exit(1);
  }

  // Set random seed
  srand(time(0));

  // Get N from command line argument
  int N = atoi(argv[1]);

  // Do the experiment and output the result
  Seq *s = new Seq(N);
  s->genseq();
  s->calprob();

  return 0;
}
