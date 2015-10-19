#ifndef CONFIGURABLEMAPPER_H
#define CONFIGURABLEMAPPER_H

#include <fstream>
class File;

#include "AbstractMapper.hpp"

class ConfigurableMapper: public AbstractMapper{

  public:
    void setMapFromFile(File& f);
    // pure virtual function, like abstract functions in Java
    virtual int adjustOffset(int i) = 0;
    virtual int readjustOffset(int i) = 0;
    virtual void accept(Visitor& v) = 0;

};

#endif
