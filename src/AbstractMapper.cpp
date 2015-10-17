#include "EnigmaConsts.hpp"

class AbstractMapper{

  public:
    AbstractMapper(){
      mapping = new int[NO_OF_LETTERS]
    }
    void setMap() {
      /* code */
    }
    // pure virtual function, like abstract functio in Java
    virtual void accept(Visitor v) = 0;
  protected:
    int* mapping;

};
