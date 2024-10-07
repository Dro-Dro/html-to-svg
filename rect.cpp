#include "rect.h"
#include <fstream>
#include <iostream>

using namespace std;

// operator<< equivalent to write the object out
ostream &Rect::write(ostream &out) const {
  out << "      <rect ";
  out << "x=\"" << x << "\" ";
  out << "y=\"" << y << "\" ";
  out << "width=\"" << width << "\" ";
  out << "height=\"" << height << "\" ";
  out << "fill=\"" << color << "\" ";
  out << " />" << endl;

  return out;
}

// operator>> equivalent to read the object contents
istream &Rect::read(istream &in) {
  in >> x >> y >> width >> height >> color;
  return in;
}