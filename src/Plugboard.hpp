#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include <iostream>
#include <fstream>
#include "ConfigurableMapper.hpp"

class Plugboard: public ConfigurableMapper{

public:
  Plugboard(std::string file);
  void accept(Visitor& v);

};

#endif
