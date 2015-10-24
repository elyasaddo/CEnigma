// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <memory>
#include "IOBoard.hpp"

using namespace std;

int main(int argc, char **argv)
{
  shared_ptr<IOBoard> ioBoard(new IOBoard(argc - 1, &(argv[1]), cin));
  ioBoard->run();

  cin.close();
  cout.close();
  return 0;
}
