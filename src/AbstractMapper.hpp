#ifndef ABSTRACTMAPPER_H
#define ABSTRACTMAPPER_H

#include <memory>

#include "Visitor.hpp"
class Visitor;

class AbstractMapper{

  public:
    AbstractMapper();
    // pure virtual functions, like abstract in Java
    virtual void setMap() = 0;
    int applyMap(int i);
    int invertMap(int i);
    // int adjustOffset(int i);
    // int readjustOffset(int i);
    virtual void accept(Visitor& v) = 0;
  protected:
    int readjustIndexAfterMap(int i);
    std::unique_ptr<int[]> mapping;
    std::unique_ptr<int[]> inverseMapping;
    int offset;

};

#endif
