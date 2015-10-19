#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include "ConfigurableMapper.hpp"

class Plugboard: public ConfigurableMapper{

public:
  void setMap();
  // virtual functions can be overridden
  // virtual int adjustOffset(int i);
  // virtual int readjustOffset(int i);
  void accept(Visitor& v);

};

#endif
