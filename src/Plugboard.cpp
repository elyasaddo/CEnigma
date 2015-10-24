#include <iostream>
#include <fstream>
#include "Plugboard.hpp"

Plugboard::Plugboard(std::ifstream &file){
  setMapFromFile(file, "pb");
}

void Plugboard::accept(Visitor& v){
  v.visit(*this);
}
