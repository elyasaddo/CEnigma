#include <iostream>
#include "..\src\CharVisitor.hpp"
#include "..\src\Reflector.hpp"

using namespace std;

int main(int argc, char const *argv[]) {

  Reflector* r = new Reflector();

  CharVisitor* c = new CharVisitor('A');
  cout << "Entering 'A' : expecting 'M'" << endl;
  r->accept(*c);
  cout << "Actual: " << c->charValue() << endl;
  delete c;

  c = new CharVisitor('R');
  cout << "Entering 'R' : expecting 'E'" << endl;
  r->accept(*c);
  cout << "Actual: " << c->charValue() << endl;
  delete c;

  delete r;

  return 0;
}
