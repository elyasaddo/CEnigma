#ifndef CHARVISITOR_H
#define CHARVISITOR_H

#include "AbstractMapper.hpp"
class AbstractMapper;

#include "Visitor.hpp"

class CharVisitor: public Visitor{

  public:
    CharVisitor(char c);
    void visit(AbstractMapper& m);
    void reflect();
    char charValue();
  protected:
    int index;
    bool isReflected;

};

#endif
