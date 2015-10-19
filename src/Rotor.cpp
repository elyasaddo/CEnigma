 #include "Rotor.hpp"
 #include "EnigmaConsts.hpp"

Rotor::Rotor(){
}

void Rotor::setMap(){

}

void Rotor::accept(Visitor& v){

}

bool Rotor::rotate(int i){
  offset++;
  bool fullyRotated = (offset == NO_OF_LETTERS);
  offset %= NO_OF_LETTERS;
  return fullyRotated;
}
