#include "CharVisitor.hpp"

CharVisitor::CharVisitor(char c){
  //PRE: c is in [A-Z]
  index = ((unsigned char) (c - 'A')) + 1;
  isReflected = false;
}

void CharVisitor::visit(AbstractMapper& m){
  if (!isReflected){
    index = m.applyMap(index);
  } else {
    index = m.invertMap(index);
  }
}

void CharVisitor::reflect(){
  isReflected = !isReflected;
}

char CharVisitor::charValue(){
  return ((char) (index - 1)) + 'A';
}
