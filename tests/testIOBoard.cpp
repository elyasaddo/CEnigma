#include <iostream>
#include <fstream>
#include <memory>
#include "IOBoard.hpp"
#include "../src/CharVisitor.hpp"
#include "../src/Plugboard.hpp"
#include "../src/Rotor.hpp"
#include "../src/Reflector.hpp"

int main(int argc, char const *argv[]) {

  shared_ptr<IOBoard> ioBoard(
                        new IOBoard(4,
                          {"../rotors/I.rot", "../rotors/I.rot",
                           "../rotors/I.rot", "../plugboards/I.pb"
                          },
                          std::cin));
  ioBoard.run();

  return 0;
}
