#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include "ConfigurableMapper.hpp"

class Plugboard: public ConfigurableMapper{

public:
  void setMap();
   void accept(Visitor& v);

};

#endif
