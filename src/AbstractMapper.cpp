#include "EnigmaConsts.hpp"
#include "AbstractMapper.hpp"

AbstractMapper::AbstractMapper(){
  mapping = new int[NO_OF_LETTERS];
}

void AbstractMapper::setMap() {

}

/* pure virtual function, like abstract functions in Java
 * virtual void accept(Visitor v) = 0;
 * so not implemented here
 */
