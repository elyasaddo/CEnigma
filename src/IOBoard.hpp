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
    IOBoard(int noOfParams, const char** filenames);
    ~IOBoard();
    void run();
  private:
    char encryptLetter(char c);
    void rotate();
    // properties
    std::vector<std::shared_ptr<Rotor>> rotors;
    std::shared_ptr<Plugboard> plugboard;
    std::shared_ptr<Reflector> reflector;
};

#endif
