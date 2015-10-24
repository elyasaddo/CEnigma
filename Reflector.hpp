#ifndef REFLECTOR_H
#define REFLECTOR_H

#include "AbstractMapper.hpp"

class Visitor;

class Reflector: public AbstractMapper{

  public:
    Reflector();
    void setMap();
    // virtual functions can be overridden
    // virtual int adjustOffset(int i);
    // virtual int readjustOffset(int i);
    void accept(Visitor& v);
};

#endif
