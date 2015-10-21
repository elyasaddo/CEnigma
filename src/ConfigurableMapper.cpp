#include <iostream>
#include <fstream>
#include <string>

#include "EnigmaConsts.hpp"
#include "ConfigurableMapper.hpp"

void ConfigurableMapper::setMap(){
  for (int i = 0; i < NO_OF_LETTERS; i++) {
    mapping[i] = i;
    inverseMapping[i] = i;
  }
}

void ConfigurableMapper::setMapFromFile(std::ifstream &f, std::string extn){
  if (extn.compare("pb")){
    ConfigurableMapper::setMap();
    int x, y;
    while (!f.eof()) {
      f >> x >> y;
      mapping[x] = y;
      mapping[y] = x;
      inverseMapping[x] = y;
      inverseMapping[y] = x;
    }
  } else if (extn.compare("rot")){
    int x;
    for (int i = 0; i < NO_OF_LETTERS; i++) {
      f >> x;
      mapping[i] = x;
      inverseMapping[x] = i;
    }
  }
  // Possible exception thrown
}

/* pure virtual function, like abstract functions in Java
 * virtual void accept(Visitor& v) = 0;
 * so not implemented here
 */
