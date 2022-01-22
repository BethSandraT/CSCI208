#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int getLines(ifstream& fs);   // Function which inputs a file name and outputs
                                    // the no. of lines inside of it
int getWords(ifstream& fs);   // Function which inputs a file name and outputs
                                    // the no. of words inside of it
int getChars(ifstream& fs);   // Function which inputs a file name and outputs
                                    // the no. of characters inside of it

int main() {
  ifstream fs;
  string filename;

  /* This is a loop used in order to verify that the input file name is valid.
  Upon an incorrect file name input, the open command will fail, and as such,
  the is_open flag will come out false. */
  do {
    cout << "Please name the file you wish to read: " << flush;
    getline (cin, filename);
    fs.open(filename);
    if (!fs.is_open() || cin.fail()) {
      cout << "File not found" << endl;
      cin.ignore(4294967295, '\n');
      cin.clear();
    }
  } while (!fs.is_open());
  cout << getLines(fs) << " " << getWords(fs) << " " << getChars(fs) << endl;
  fs.close();
  return 0;
}

int getLines(ifstream& fs) {
  char chr;
  int lines = 0;
  fs.clear();   // Redundant for this specific use, but I wanted a
                      // generalized option in case the order was ever switched
  fs.seekg(0);  // Redundant for this specific use, but I wanted a
                      // generalized option in case the order was ever switched
  if (fs.is_open()) {
    if (fs.eof()) { // If the file is empty, there are no lines
      return 0;
    }

    do {                  // The loop iterates once, then if the end of the file
                          // is NOT reached, the loop iterates again
      fs.get(chr);
      if (chr == '\n') {  // Each newline signifies a new line,
        ++lines;          // which adds to the line count
      }
    } while (!fs.eof());
  }
  return lines;
}

int getWords(ifstream& fs) {
  char chr;
  int words = 0;
  bool prevWasSpace = 1;
  fs.clear();
  fs.seekg(0);
  if (fs.is_open()) {
    if (fs.eof()) { // If the file is empty, there are no words
      return 0;
    }

    do {
      fs.get(chr);
      if (!isspace(chr)) {  // If the char is not whitespace,
        if (prevWasSpace) { // and the previous char was,
          ++words;          // that means the char begins another word
        }
        prevWasSpace = 0;
      }
      else {
        prevWasSpace = 1;
      }
    } while (!fs.eof());
  }
  return words;
}

int getChars(ifstream& fs) {
  char chr;
  int characters = 0;
  fs.clear();
  fs.seekg(0);
  if (fs.is_open()) {
    while (!fs.eof()) { // If not at the end of file,
      fs.get(chr);      // get the next character from the file
      if (!isspace(chr)) {    // and if it's not whitespace,
        ++characters;         // add one to the count of characters
      }
    }
  }
  return characters;
}
