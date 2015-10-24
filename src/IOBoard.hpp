#ifndef IOBOARD_H
#define IOBOARD_H

#include <istream>
#include <vector>
#include <memory>
#include "Rotor.hpp"
#include "Plugboard.hpp"
#include "Reflector.hpp"

class IOBoard{

  public:
    IOBoard(int noOfParams, const char** filenames, std::istream& input);
    void run();
  private:
    char encryptLetter(char c);
    void rotate();
    // properties
    std::istream* inputStream;
    std::vector<Rotor*> rotors;
    std::shared_ptr<Plugboard> plugboard;
    std::shared_ptr<Reflector> reflector;
};

#endif
