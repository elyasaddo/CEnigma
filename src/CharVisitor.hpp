#ifndef CHARVISITOR_H
#define CHARVISITOR_H

#include "AbstractMapper.hpp"
class AbstractMapper;

#include "Visitor.hpp"

class CharVisitor: public Visitor{

  public:
    CharVisitor(int i);
    void visit(AbstractMapper& m);
  protected:
    int index;

};

#endif
