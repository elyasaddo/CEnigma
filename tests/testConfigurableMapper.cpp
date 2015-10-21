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

private void testPlugboards(Plugboard &p);
private void testRotors(rotor &r);

int main(int argc, char const *argv[]) {

  shared_ptr<Rotor> rotor(new Rotor());
  shared_ptr<Plugboard> pboard(new Plugboard());

  ifstream rotorConf;
  rotorConf.open("../rotors/I.rot", ios::in); // conf: 1 2 3 4 5 6 7 8 9 10 11 ... 0
  rotor.setMapFromFile(rotorConf , "rot");
  ifstream pboardConf;
  pboardConf.open("../plugboards/I.pb", ios::in); //conf: 25 8
  pboard.setMapFromFile(pboard, "pb");

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
  pboard->accept(*c);
  cout << "Actual: " << c->charValue() << endl;

  c = make_shared<CharVisitor> ('R');
  c->reflect();
  cout << "Entering 'R' : expecting 'R'" << endl;
  pboard->accept(*c);
  cout << "Actual: " << c->charValue() << endl;

  c = make_shared<CharVisitor> ('H');
  cout << "Entering 'H' : expecting 'Z'" << endl;
  pboard->accept(*c);
  cout << "Actual: " << c->charValue() << endl;

  c->reflect();
  cout << "Entering 'Z' : expecting 'H'" << endl;
  pboard->accept(*c);
  cout << "Actual: " << c->charValue() << endl;
}

void testRotors(Rotor &r){
  shared_ptr<CharVisitor> c(new CharVisitor('A'));
  cout << "testing plugboards" << endl;
  cout << "Entering 'A' : expecting 'B'" << endl;
  pboard->accept(*c);
  cout << "Actual: " << c->charValue() << endl;

  c = make_shared<CharVisitor> ('R');
  c->reflect();
  cout << "Entering 'R' : expecting 'Q'" << endl;
  pboard->accept(*c);
  cout << "Actual: " << c->charValue() << endl;

  c = make_shared<CharVisitor> ('H');
  cout << "Entering 'H' : expecting 'I'" << endl;
  pboard->accept(*c);
  cout << "Actual: " << c->charValue() << endl;

  c->reflect();
  cout << "Entering 'I' : expecting 'H'" << endl;
  pboard->accept(*c);
  cout << "Actual: " << c->charValue() << endl;
}
