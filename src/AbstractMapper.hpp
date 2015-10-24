#ifndef ABSTRACTMAPPER_H
#define ABSTRACTMAPPER_H

#include "Visitor.hpp"
class Visitor;

class AbstractMapper{

  public:
    AbstractMapper();
    ~AbstractMapper();
    // pure virtual functions, like abstract in Java
    virtual void setMap() = 0;
    int applyMap(int i);
    int invertMap(int i);
    // int adjustOffset(int i);
    // int readjustOffset(int i);
    virtual void accept(Visitor& v) = 0;
  protected:
    int* mapping;
    int* inverseMapping;
    int offset;

};

#endif
