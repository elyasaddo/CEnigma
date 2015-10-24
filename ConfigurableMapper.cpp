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
  if (extn.compare("pb") == 0){
    ConfigurableMapper::setMap();
    int x, y;
    while (!f.eof()) {
      f >> x >> y;
      mapping[x] = y;
      mapping[y] = x;
      // cannot use inverseMapping.reset(mapping) since both arrays are unique_ptrs
      inverseMapping[x] = y;
      inverseMapping[y] = x;
    }
  } else if (extn.compare("rot") == 0){
    int x;
    for (int i = 0; i < NO_OF_LETTERS; i++) {
      f >> x;
      mapping[i] = x;
      inverseMapping[x] = i;
    }
  }
  
  // std::cout << std::endl;
  // for (int i = 0; i < NO_OF_LETTERS; i++) {
  //   std::cout << mapping[i] << ' ';
  // }
  // Possible exception thrown
}

/* pure virtual function, like abstract functions in Java
 * virtual void accept(Visitor& v) = 0;
 * so not implemented here
 */
