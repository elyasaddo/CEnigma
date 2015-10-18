#ifndef ROTOR_H
#define ROTOR_H

#include "Visitor.hpp"
class Visitor;

#include "ConfigurableMapper.hpp"

class Rotor: public ConfigurableMapper{

public:
  void setMap();
  void accept(Visitor& v);
};

#endif
