#include <stdexcept>
#include <iostream>
#include <fstream>
#include <memory>
#include "IOBoard.hpp"

using namespace std;

int main(int argc, char **argv)
{
  shared_ptr<IOBoard> ioBoard(
          new IOBoard(argc - 1, (const char**) &(argv[1]), cin));
  ioBoard->run();

  return 0;
}
