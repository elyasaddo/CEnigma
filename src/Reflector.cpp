#include "Reflector.hpp"
#include "EnigmaConsts.hpp"

Reflector::Reflector(){
  Reflector::setMap();
}

void Reflector::setMap(){
  for (int i = 0; i < NO_OF_LETTERS; i++) {
    mapping[i] = (i + NO_OF_LETTERS / 2) % NO_OF_LETTERS;
    inverseMapping[i] = mapping[i];
  }
}

void Reflector::accept(Visitor& v){
  v.visit(*this);
}
