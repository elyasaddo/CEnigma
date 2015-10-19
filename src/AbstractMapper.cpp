#include "EnigmaConsts.hpp"
#include "AbstractMapper.hpp"

AbstractMapper::AbstractMapper(){
  mapping = new int[NO_OF_LETTERS];
}

int AbstractMapper::applyMap(int i){
  return 0;
}

int AbstractMapper::invertMap(int i){
  return 25;
}
/* pure virtual function, like abstract functions in Java
 * virtual void setMap() = 0;
 * virtual int adjustOffset(int i) = 0;
 * virtual int readjustOffset(int i) = 0;
 * virtual void accept(Visitor& v) = 0;
 * so not implemented here
 */
