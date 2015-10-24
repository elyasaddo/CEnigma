#include <iostream>
#include "EnigmaConsts.hpp"
#include "AbstractMapper.hpp"

AbstractMapper::AbstractMapper(){
  offset = 0;
  mapping.reset(new int[NO_OF_LETTERS]);
  inverseMapping.reset(new int[NO_OF_LETTERS]);
}

// PRE 0 <= i < NO_OF_LETTERS
int AbstractMapper::applyMap(int i){
  i += offset;
  std::cout << '|' << i % NO_OF_LETTERS << ' ';
  i = mapping[i % NO_OF_LETTERS];
  return readjustIndexAfterMap(i);
}

int AbstractMapper::invertMap(int i){
  i += offset;
  std::cout << i % NO_OF_LETTERS << ' ';
  i = inverseMapping[i % NO_OF_LETTERS];
  return readjustIndexAfterMap(i);
}

int AbstractMapper::readjustIndexAfterMap(int i){
  i -= offset;
  i += NO_OF_LETTERS;
  i %= NO_OF_LETTERS;
}

/* pure virtual function, like abstract functions in Java
 * virtual void setMap() = 0;
 * virtual int adjustOffset(int i) = 0;
 * virtual int readjustOffset(int i) = 0;
 * virtual void accept(Visitor& v) = 0;
 * so not implemented here
 */
