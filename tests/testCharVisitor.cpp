#include <iostream>
#include <memory>
#include "../src/CharVisitor.hpp"
#include "../src/Reflector.hpp"

using namespace std;

int main(int argc, char const *argv[]) {

  shared_ptr<Reflector> r(new Reflector());

  shared_ptr<CharVisitor> c(new CharVisitor('A'));
  cout << "Entering 'A' : expecting 'N'" << endl;
  r->accept(*c);
  cout << "Actual: " << c->charValue() << endl;

  c.reset(new CharVisitor('R'));
  cout << "Entering 'R' : expecting 'E'" << endl;
  r->accept(*c);
  cout << "Actual: " << c->charValue() << endl;

  // Garbage collector handles deletion of shared_ptr(s)
  return 0;
}
