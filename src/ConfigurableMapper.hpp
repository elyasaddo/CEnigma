#ifndef CONFIGURABLEMAPPER_H
#define CONFIGURABLEMAPPER_H

#include <fstream>
#include <string>

#include "AbstractMapper.hpp"

class ConfigurableMapper: public AbstractMapper{

  public:
    void setMap();
    void setMapFromFile(std::ifstream &f, std::string extn);
    // pure virtual function, like abstract functions in Java
    virtual void accept(Visitor& v) = 0;

};

#endif
