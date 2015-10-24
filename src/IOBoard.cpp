#include <iostream>
#include <fstream>
#include <cctype>
#include <memory>
#include <iterator>
#include "IOBoard.hpp"
#include "CharVisitor.hpp"

IOBoard::IOBoard(int noOfParams, const char** filenames, std::istream& input){
  inputStream = &input;
  // set up rotors
  // 0 indexed, all but last are rotors
  //Rotor* r;
  for (int i = 0; i <= noOfParams - 2; i++) {
    //r = (new Rotor(filenames[i]));
    rotors.push_back(new Rotor(filenames[i]));
  }
  // set up plugboard
  plugboard = std::make_shared<Plugboard> (filenames[noOfParams-1]);
  // set up reflector
  reflector = std::make_shared<Reflector> ();
}

void IOBoard::run(){
  char c;
  while(inputStream->get(c)){
    std::cout << encryptLetter(c); 
  }
}

char IOBoard::encryptLetter(char c){

  if (isupper(c)){
    std::shared_ptr<CharVisitor> cv(new CharVisitor(c));
    
    plugboard->accept(*cv);
    for (std::vector<Rotor*>::iterator rItr = rotors.begin(); 
            rItr != rotors.end(); rItr++){
      (*rItr)->accept(*cv);
    }
    reflector->accept(*cv);
    cv->reflect();
    for (std::vector<Rotor*>::reverse_iterator rItr = rotors.rbegin(); 
            rItr != rotors.rend(); rItr++){ // note the Rbegin and Rend
      (*rItr)->accept(*cv);
    }
    plugboard->accept(*cv);

    rotate();
    return cv->charValue();

  } else if (!isspace(c)){
    std::cerr << std::endl <<  '\'' << c << "' is not a valid character.";
    std::cerr << std::endl << "Only uppercase letters and spaces allowed.";
    std::cerr << std::endl;
  }

  return c; // returns c if it is a white space
}

void IOBoard::rotate(){
  std::vector<Rotor*>::iterator rItr = rotors.begin();
  while(rItr != rotors.end()){
    if ( !(*rItr)->rotate(1)){
      // if this rotor is not fully rotated, don't rotate the next
      break;
    }
  }
}
