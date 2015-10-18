#ifndef ROTATEVISITOR_H
#define ROTATEVISITOR_H

#include "AbstractMapper.hpp"
class AbstractMapper;

class RotateVisitor: public Visitor{

  public:
    void visit(AbstractMapper& m);

};

#endif
