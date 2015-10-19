#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include "ConfigurableMapper.hpp"

class Plugboard: public ConfigurableMapper{

public:
  void setMap();
  int adjustOffset(int i);
  int readjustOffset(int i);
  void accept(Visitor& v);

};

#endif
