#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

int getLines(string filename);  // Function which inputs a file name and outputs
                                // the no. of lines inside of it
int getWords(string filename);  // Function which inputs a file name and outputs
                                // the no. of words inside of it
int getChars(string filename);  // Function which inputs a file name and outputs
                                // the no. of characters inside of it

int main() {
  string filename;

  /* This is a loop used in order to verify that the input file name is valid.
  Upon an incorrect file name input, the open command will fail, and as such,
  the is_open flag will come out false. */
  do {
    cout << "Please name the file you wish to read: " << flush;
    getline (cin, filename);
    ifstream filename;
    open (filename, in);
    if (!filename.is_open() || cin.fail()) {
      cout << "File not found" << endl;
      cin.ignore(4294967295, '\n');
      cin.clear();
    }
  } while (filename.is_open());
  cout << getLines(filename) << " " << getWords(filename) << " " << getChars(filename) << endl;
  return 0;
}

int getLines(string filename) {
  char chr;
  int lines = 0;
  filename.clear();   // Redundant for this specific use, but I wanted a
                      // generalized option in case the order was ever switched
  filename.seekg(0);  // Redundant for this specific use, but I wanted a
                      // generalized option in case the order was ever switched
  if (filename.is_open()) {
    if (filename.eof()) { // If the file is empty, there are no lines
      return 0;
    }

    do {
      filename.get(chr);
      if (chr == '\n') {
        ++lines;
      }
    } while (!filename.eof());
  }
}

int getWords(string filename) {
  filename.clear();
  filename.seekg(0);
}

int getChars(string filename) {
  filename.clear();
  filename.seekg(0);
}
