#include <stdexcept>
#include <iostream>
#include <fstream>
#include <memory>
#include "IOBoard.hpp"

using namespace std;

int main(int argc, char **argv)
{
   if (argc < 2){
     throw invalid_argument("Need at least a plugboard (.pb) file");
   }
   shared_ptr<IOBoard> ioBoard(
           new IOBoard(argc - 1, (const char**) &(argv[1])));
   ioBoard->run();

  return 0;
}
