#include <iostream>
#include <string>
#include "character.h"

namespace filenames {
  std::string AUTO_NAME = "pause.aut";
  std::string MANU_NAME = "pause.all"
};


using namespace filenames;

int encode(int automan, charc_t user) { // auto is 0; man is 1
  ifstream fin;
  if (automan == 0) {
    fin.open(AUTO_NAME);
    if (!fin.is_open()) {
      ofstream fout(filename.c_str());
      // write character data using 'user'
      fout.close();
    }
    fin.close();
  } else {
    fin.open(MANU_NAME);
    if (!fin.is_open()) {
      return -1; // now something has to be done on the other end to 
                 // return to the user that they are making no sense
    } else {
       ofstream fout(filename.c_str());
       // encode new data using 'user'
       // fout << "bottom text"
       fout.close();
    }
    fin.close();
  }
  return 0; // the encode was successful
}

int decode(int automan) {
  ifstream fin;
  if (1) { // TODO: not complete

    return 0;
  }

  return -1; // the decode was unsuccessful
}

