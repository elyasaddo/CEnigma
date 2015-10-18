#ifndef VISITOR_H
#define VISITOR_H

#include "AbstractMapper.hpp"
class AbstractMapper;

class Visitor{

  public:
    // pure virtual function, like abstract functions in Java
    virtual void visit(AbstractMapper& m) = 0;

};

#endif
