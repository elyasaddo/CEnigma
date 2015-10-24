#include "EnigmaConsts.hpp"
#include "AbstractMapper.hpp"

AbstractMapper::AbstractMapper(){
  offset = 0;
  mapping = new int[NO_OF_LETTERS];
  inverseMapping = new int[NO_OF_LETTERS];
}

AbstractMapper::~AbstractMapper(){
  delete[] mapping;
  delete[] inverseMapping;
}

// PRE 0 <= i < NO_OF_LETTERS
int AbstractMapper::applyMap(int i){
  i += offset;
  i = mapping[i];
  i -= offset;
  return i;
}

int AbstractMapper::invertMap(int i){
  i += offset;
  i = inverseMapping[i];
  i -= offset;
  return i;
}

/* pure virtual function, like abstract functions in Java
 * virtual void setMap() = 0;
 * virtual int adjustOffset(int i) = 0;
 * virtual int readjustOffset(int i) = 0;
 * virtual void accept(Visitor& v) = 0;
 * so not implemented here
 */
