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
  std::string text;
  inputStream >> text;
  for (str:string::iterator itr = text.begin(); itr != text.end(); ++itr) {
    text[i] = encryptLetter(text[0]);
    rotate();
  }
  std::cout << text << std::endl;
}

char encryptLetter(char c){
  return c;
}

void rotate(){

}
