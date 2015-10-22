#include <iostream>
#include <fstream>
#include "IOBoard.hpp"

IOBoard::IOBoard(int noOfParams, char** filenames, std::istream input);

void run();
  private:
    void encryptLetter(char c);
    void rotate();
    // properties
    vector<Rotor> rotors;
