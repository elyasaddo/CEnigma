#ifndef ABSTRACTMAPPER_H
#define ABSTRACTMAPPER_H

#include "Visitor.hpp"
class Visitor;

class AbstractMapper{

  public:
    AbstractMapper();
    void setMap();
    // pure virtual function, like abstract functions in Java
    virtual void accept(Visitor& v) = 0;
  protected:
    int* mapping;

};

#endif
