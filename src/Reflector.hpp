#ifndef REFLECTOR_H
#define REFLECTOR_H

#include "AbstractMapper.hpp"

class Visitor;

class Reflector: public AbstractMapper{

  public:
    Reflector();
    void setMap();
    int adjustOffset(int i);
    int readjustOffset(int i);
    void accept(Visitor& v);
};

#endif
