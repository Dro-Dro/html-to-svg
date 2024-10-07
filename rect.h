/**
 * SVG Rectangle/Square
 **/

#ifndef RECT_H
#define RECT_H

#include "svg.h"
#include <iostream>
#include <string>

using namespace std;

class Rect : public SVG {

public:
  // operator<< equivalent to write the object out
  ostream &write(ostream &out) const override;

  // operator>> equivalent to read the object contents
  istream &read(istream &in) override;

private:
  // coordinates for left and top edges of the rectangle
  int x{0}, y{0};

  // values for width and height of rectangle
  int width{0}, height{0};

  // color of rectangle
  string color{"black"};
};

#endif
