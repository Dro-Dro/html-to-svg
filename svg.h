/**
 * Base object type for Scalable Vector Graphics.
 **/

#ifndef SVG_H
#define SVG_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SVG {
  friend ostream &operator<<(ostream &out, const SVG &svg) {
    return svg.write(out);
  }
  friend istream &operator>>(istream &ins, SVG &svg) { return svg.read(ins); }

public:
  // operator<< equivalent to write the object out
  virtual ostream &write(ostream &out) const = 0;

  // operator>> equivalent to read the object contents
  virtual istream &read(istream &in) = 0;

  // default constructor
  SVG() = default;

  // default virtual destructor
  virtual ~SVG() = default;

  // copy not allowed
  SVG(const SVG &other) = delete;

  // move not allowed
  SVG(SVG &&other) = delete;

  // assignment not allowed
  SVG &operator=(const SVG &other) = delete;

  // move assignment not allowed
  SVG &operator=(SVG &&other) = delete;
};

#endif
