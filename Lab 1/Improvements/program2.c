/**
 * Author: Devansh Jain (190100044)
 * Lab 1 - Progam 2 - Procedural:
 * A program that reads a text file,
 * whose name is supplied as command line parameter,
 * and it prints the frequency of counts of
 * every single letter/character appearing in that file.
 */

#include <stdio.h>  // IO library
#include <stdlib.h> // Standard library

/**
 * @struct data
 * @brief stores the frequency of all characters
 *        mapped to their ASCII values
 */
struct data {
  int freq[256];
};

/**
 * @fn calfreq
 * @param[out] f the calculated frequency mapping
 * @param[in] file_name input file name
 * @brief opens the file and reads it char-by-char
 *        and increments the frequency counter for the char
 */
void calfreq(struct data *f, char *file_name) {
  for (int i = 0; i < 256; i++) {
    f->freq[i] = 0;
  }

  FILE *fp = fopen(file_name, "r");

  if (fp == NULL)
    return;

  while (1) {
    char c = fgetc(fp);

    if (feof(fp))
      break;

    f->freq[(int)c]++;
  }

  fclose(fp);
}

/**
 * @fn printfreq
 * @param[in] f the frequency mapping
 * @brief prints the frequency of all characters with non-zero count
 */
void printfreq(struct data *f) {
  for (int i = 0; i < 256; i++) {
    if (f->freq[i] != 0) {
      printf("%c: %i\n", i, f->freq[i]);
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
  struct data d;
  calfreq(&d, file);
  printfreq(&d);

  return 0;
}
