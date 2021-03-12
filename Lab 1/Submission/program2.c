#include <stdio.h>
#include <string.h>

using namespace std;

struct data {
  int freq[256];
};

void countFreq(struct data *f, char *file_name) {
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

    f->freq[int(c)]++;
  }

  fclose(fp);
}

void printFreq(struct data *f) {
  for (int i = 0; i < 256; i++) {
    if (f->freq[i] != 0) {
      printf("%c: %i\n", i, f->freq[i]);
    }
  }
}

int main(int argc, char *argv[]) {

  if (argc > 1) {
    struct data *d = new struct data();

    countFreq(d, argv[1]);
    printFreq(d);
  }

  return 0;
}
