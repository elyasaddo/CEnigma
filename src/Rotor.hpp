#ifndef ROTOR_H
#define ROTOR_H

#include "Visitor.hpp"
class Visitor;

#include "ConfigurableMapper.hpp"

class Rotor: public ConfigurableMapper{

public:
  Rotor();
  void setMap();
  void accept(Visitor& v);
  // overrides AbstractMapper::rotate(int)
  virtual void rotate(int i);
private:
  int rotatedAmount;
};

#endif
