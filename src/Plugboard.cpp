#include <iostream>
#include <fstream>
#include "Plugboard.hpp"

Plugboard::Plugboard(std::string file){
  std::ifstream pboardConf;
  pboardConf.open(file, std::ios::in);
  setMapFromFile(pboardConf, "pb");
  pboardConf.close();
}

void Plugboard::accept(Visitor& v){
  v.visit(*this);
}
