#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <memory>
#include <iterator>
#include "IOBoard.hpp"
#include "CharVisitor.hpp"

IOBoard::IOBoard(int noOfParams, const char** filenames){
  // set up rotors
  // 0 indexed, all but last are rotors
  std::ifstream rotorConf;
  for (int i = 0; i <= noOfParams - 2; i++) {
    rotorConf.open(filenames[i], std::ios::in);
    if (!rotorConf.is_open()) 
      throw std::invalid_argument("File does not exist");
    rotors.push_back(std::make_shared<Rotor> (rotorConf));
    rotorConf.close();
  }
  // set up plugboard
  std::ifstream pboardConf;
  pboardConf.open(filenames[noOfParams-1], std::ios::in);
  if (!pboardConf.is_open()) 
    throw std::invalid_argument("File does not exist");
  plugboard = std::make_shared<Plugboard> (pboardConf);
  pboardConf.close();
  // set up reflector
  reflector = std::make_shared<Reflector> ();
}

IOBoard::~IOBoard(){
  rotors.clear();
}

void IOBoard::run(){
  char c;
  while(std::cin >> std::ws >> c){
    std::cout << encryptLetter(c);
  }
}

char IOBoard::encryptLetter(char c){

  if (isupper(c)){
    std::shared_ptr<CharVisitor> cv(new CharVisitor(c));

    plugboard->accept(*cv);
    for (std::vector<std::shared_ptr<Rotor>>::iterator rItr = rotors.begin();
            rItr != rotors.end(); rItr++){
      (*rItr)->accept(*cv);
    }
    reflector->accept(*cv);
    cv->reflect();
    for (std::vector<std::shared_ptr<Rotor>>::reverse_iterator rItr
            = rotors.rbegin();
            rItr != rotors.rend(); rItr++){ // note the Rbegin and Rend
      (*rItr)->accept(*cv);
    }
    plugboard->accept(*cv);

    rotate();
    return cv->charValue();

  } else {
    std::string message = "'";
    message += c;
    message += "' is not a valid character.\n";
    message += "Only uppercase letters and spaces allowed.\n";
    throw std::invalid_argument(message);
  }

  return c; // returns c if it is a white space
}

void IOBoard::rotate(){
  std::vector<std::shared_ptr<Rotor>>::iterator rItr = rotors.begin();
  while(rItr != rotors.end()){
    if ( !(*rItr)->rotate(1))
      // if this rotor is not fully rotated, don't rotate the next
      break;
  rItr++;
  }
}
