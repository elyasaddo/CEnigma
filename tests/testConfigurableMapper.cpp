#include <iostream>
#include <fstream>
#include <memory>
#include "../src/CharVisitor.hpp"
#include "../src/AbstractMapper.hpp"
#include "../src/ConfigurableMapper.hpp"
#include "../src/Plugboard.hpp"
#include "../src/Rotor.hpp"
#include "../src/Reflector.hpp"

using namespace std;

void testPlugboards(Plugboard &p);
void testRotors(Rotor &r);

int main(int argc, char const *argv[]) {

  shared_ptr<Rotor> rotor;
  shared_ptr<Plugboard> pboard);

  ifstream rotorConf;
  rotorConf.open("../rotors/I.rot", ios::in); // conf: 1 2 3 4 5 6 7 8 9 10 11 ... 0
  rotor.reset(rotorConf);
  rotorConf.close();
  ifstream pboardConf;
  pboardConf.open("../plugboards/I.pb", ios::in); //conf: 25 8
  pboard.reset(pboardConf);
  pboardConf.close();

  testPlugboards(*pboard);
  cout << endl;
  testRotors(*rotor);

  // Garbage collector handles deletion of shared_ptr(s)
  return 0;
}

void testPlugboards(Plugboard &p){
  shared_ptr<CharVisitor> c(new CharVisitor('A'));
  cout << "testing plugboards" << endl;
  cout << "Entering 'A' : expecting 'A'" << endl;
  p.accept(*c);
  cout << "Actual: " << c->charValue() << endl;

  c.reset(new CharVisitor('R'));
  c->reflect();
  cout << "Entering 'R' : expecting 'R'" << endl;
  p.accept(*c);
  cout << "Actual: " << c->charValue() << endl;

  c.reset(new CharVisitor('H'));
  cout << "Entering 'H' : expecting 'H'" << endl;
  p.accept(*c);
  cout << "Actual: " << c->charValue() << endl;

  c.reset(new CharVisitor('Z'));
  cout << "Entering 'Z' : expecting 'I'" << endl;
  p.accept(*c);
  cout << "Actual: " << c->charValue() << endl;
  c->reflect();
  cout << "Entering 'I' : expecting 'Z'" << endl;
  p.accept(*c);
  cout << "Actual: " << c->charValue() << endl;
}

void testRotors(Rotor &r){
  shared_ptr<CharVisitor> c(new CharVisitor('A'));
  cout << "testing plugboards" << endl;
  cout << "Entering 'A' : expecting 'B'" << endl;
  r.accept(*c);
  cout << "Actual: " << c->charValue() << endl;

  c.reset(new CharVisitor('R'));
  c->reflect();
  cout << "Entering 'R' : expecting 'Q'" << endl;
  r.accept(*c);
  cout << "Actual: " << c->charValue() << endl;

  c.reset(new CharVisitor('H'));
  cout << "Entering 'H' : expecting 'I'" << endl;
  r.accept(*c);
  cout << "Actual: " << c->charValue() << endl;

  c->reflect();
  cout << "Entering 'I' : expecting 'H'" << endl;
  r.accept(*c);
  cout << "Actual: " << c->charValue() << endl;
}
