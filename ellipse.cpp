#include "ellipse.h"
#include <fstream>
#include <iostream>

using namespace std;

// operator<< equivalent to write the object out
ostream &Ellipse::write(ostream &out) const {
  out << "      <ellipse ";
  out << "cx=\"" << cx << "\" ";
  out << "cy=\"" << cy << "\" ";
  out << "rx=\"" << rx << "\" ";
  out << "ry=\"" << ry << "\" ";
  out << "fill=\"" << color << "\" ";
  out << " />" << endl;

  return out;
}

// operator>> equivalent to read the object contents
istream &Ellipse::read(istream &in) {
  in >> cx >> cy >> rx >> ry >> color;
  return in;
}