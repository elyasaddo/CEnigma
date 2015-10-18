#ifndef CONFIGURABLEMAPPER_H
#define CONFIGURABLEMAPPER_H

#include <fstream>
class File;

#include "AbstractMapper.hpp"

class ConfigurableMapper: public AbstractMapper{

  public:
    void setMapFromFile(File& f);
    // pure virtual function, like abstract functions in Java
    virtual void accept(Visitor& v) = 0;

};

#endif
