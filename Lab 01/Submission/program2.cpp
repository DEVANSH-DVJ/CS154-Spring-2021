#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

class Data {
  int freq[256];
  char *name;

public:
  Data(char *file_name);
  void countFreq();
  void printFreq();
};

Data::Data(char *file_name) {
  name = file_name;
  for (int i = 0; i < 256; i++) {
    freq[i] = 0;
  }
}

void Data::countFreq() {
  ifstream is(name);

  char c;
  while (is.get(c))
    freq[int(c)]++;

  is.close();
}

void Data::printFreq() {
  for (int i = 0; i < 256; i++) {
    if (freq[i] != 0) {
      cout << char(i) << ": " << freq[i] << endl;
    }
  }
}

int main(int argc, char *argv[]) {

  if (argc > 1) {
    Data *d = new Data(argv[1]);

    d->countFreq();
    d->printFreq();
  }

  return 0;
}
