#ifndef IOBOARD_H
#define IOBOARD_H

#include <istream>
#include <vector>
#include "Rotor.hpp"

class IOBoard{

  public:
    IOBoard(int noOfParams, char** filenames, std::istream input);
    void run();
  private:
    void encryptLetter(char c);
    void rotate();
    // properties
    vector<Rotor> rotors;

}

#endif
