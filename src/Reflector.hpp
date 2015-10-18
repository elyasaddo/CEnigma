#ifndef REFLECTOR_H
#define REFLECTOR_H

#include "AbstractMapper.hpp"

class Visitor;

class Reflector: public AbstractMapper{

  public:
    void setMap();
    void accept(Visitor& v);
};

#endif
