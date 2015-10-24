#include <iostream>
#include <fstream>
#include "IOBoard.hpp"

IOBoard::IOBoard(int noOfParams, char** filenames, std::istream input){
  inputStream = input;
  // set up rotors
  // 0 indexed, all but last are rotors
  for (int i = 0; i < noOfParams - 2; i++) {
    Rotor* r = new Rotor(filenames[i]);
    rotors.push_back();
  }
  // set up plugboard
  plugboard = make_shared<Plugboard> (filenames[noOfParams-1]);
  // set up reflector
  reflector = make_shared<Reflector> ();
}

void IOBoard::run(){
  char c;
  while(inputStream.get(c)){
    std::cout << encryptLetter(c) << std::endl;
    rotate();
  }
}

char encryptLetter(char c){
  return c;
}

void rotate(){

}
