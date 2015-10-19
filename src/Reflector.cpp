#include "Reflector.hpp"
#include "EnigmaConsts.hpp"

Reflector::Reflector(){
  Reflector::setMap();
}

void Reflector::setMap(){
  for (int i = 0; i < NO_OF_LETTERS; i++) {
    mapping[i] = (i + NO_OF_LETTERS / 2) % NO_OF_LETTERS;
  }
}

int adjustOffset(int i){
  return i;
}

int readjustOffset(int i){
  return i;
}

void Reflector::accept(Visitor& v){
  v.visit(*this);
}
