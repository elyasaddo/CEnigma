#include <iostream>
#include <fstream>
#include "Rotor.hpp"
#include "EnigmaConsts.hpp"

Rotor::Rotor(std::ifstream &file){
  setMapFromFile(rotorConf, "rot");
}

void Rotor::accept(Visitor& v){
  v.visit(*this);
}

bool Rotor::rotate(int i){
  offset += i;
  while (offset < 0){
    offset += NO_OF_LETTERS;
  }
  // will only count 1st full rotation
  bool fullyRotated = (offset >= NO_OF_LETTERS);
  offset %= NO_OF_LETTERS;
  return fullyRotated;
}
