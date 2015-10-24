#include <iostream>
#include <fstream>
#include <memory>
#include "../src/IOBoard.hpp"
#include "../src/CharVisitor.hpp"
#include "../src/Plugboard.hpp"
#include "../src/Rotor.hpp"
#include "../src/Reflector.hpp"

int main(int argc, char const *argv[]) {

  std::shared_ptr<IOBoard> ioBoard(new IOBoard(argc - 1, &(argv[1]), std::cin));
  ioBoard->run();

  return 0;
}
