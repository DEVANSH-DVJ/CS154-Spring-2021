/**
 * Author: Devansh Jain (190100044)
 * Lab 1 - Progam 2 - Object Oriented:
 * A program that reads a text file,
 * whose name is supplied as command line parameter,
 * and it prints the frequency of counts of
 * every single letter/character appearing in that file.
 */

#include <fstream>
#include <iostream>

using namespace std;

/**
 * @class Seq
 * @brief stores file name and the frequency of all characters
 *        mapped to their ASCII values
 */
class Data {
  int freq[256];
  char *name;

public:
  /**
   * @ctor Data
   * @param[in] file_name input file name
   * @brief sets the frequency count of all characters to 0
   */
  Data(char *file_name);

  /**
   * @fn calfreq
   * @brief opens the file and reads it char-by-char
   *        and increments the frequency counter for the char
   */
  void calfreq();

  /**
   * @fn print
   * @brief prints the frequency of all characters with non-zero count
   */
  void print();
};

Data::Data(char *file_name) {
  name = file_name;
  for (int i = 0; i < 256; i++) {
    freq[i] = 0;
  }
}

void Data::calfreq() {
  ifstream is(name);

  char c;
  while (is.get(c))
    freq[int(c)]++;

  is.close();
}

void Data::print() {
  for (int i = 0; i < 256; i++) {
    if (freq[i] != 0) {
      cout << char(i) << ": " << freq[i] << endl;
    }
  }
}

int main(int argc, char *argv[]) {

  // Check the number of arguments
  if (argc != 2) {
    printf("Usage: %s <file name>\n", argv[0]);
    exit(1);
  }

  // Get file name from command line argument
  char *file = argv[1];

  // Do the frequency count and output the result
  Data *d = new Data(file);
  d->calfreq();
  d->print();

  return 0;
}
