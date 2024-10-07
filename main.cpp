#include "circle.h"
#include "ellipse.h"
#include "rect.h"
#include "svg.h"
#include <fstream>
#include <iostream>

using namespace std;

// read inFile, return vector of SVG* objects
vector<SVG *> readSVGFile(const string &inFile) {
  vector<SVG *> svgs;
  ifstream fin(inFile);
  if (!fin.good()) {
    cout << "Failed to open: " << inFile << endl;
    return svgs;
  }
  string sType;
  SVG *obj = nullptr;
  while (fin >> sType) {
    cout << "Reading: " << sType << endl;
    if (sType == "circle") {
      obj = new Circle();
    } else if (sType == "rect") {
      obj = new Rect();
    } else if (sType == "ellipse") {
      obj = new Ellipse();
    } else {
      cout << "Unrecognized type: " << sType << endl;
      string junk;
      getline(fin, junk);
      obj = nullptr;
    }
    if (obj != nullptr) {
      fin >> *obj;
      svgs.push_back(obj);
    }
  }
  fin.close();
  return svgs;
}

// write outFile, return true if successful
bool writeSVGFile(const string &outFile, vector<SVG *> &svgs) {
  if (svgs.empty()) {
    return false;
  }
  ofstream fout(outFile);
  if (!fout.good()) {
    cout << "Failed to write to: " << outFile << endl;
    return false;
  }
  // raw string R"(...)
  fout << R"(<?xml version="1.0"?>)" << endl;
  fout << R"(<!DOCTYPE svg PUBLIC "-//W3C//DTD SVG 1.1//EN" )";
  fout << R"("http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd">)" << endl;
  fout << R"(<svg xmlns="http://www.w3.org/2000/svg" version="1.1" )";
  fout << R"(width="800" height="800">)" << endl;
  for (auto *obj : svgs) {
    obj->write(fout);
  }
  fout << "</svg>" << endl;
  fout.close();
  return true;
}

// read inFile, write outFile as HTML. return true if successful
bool processSVGFile(const string &inFile, const string &outFile) {
  auto svgs = readSVGFile(inFile);
  bool result = writeSVGFile(outFile, svgs);
  for (auto *obj : svgs) {
    delete obj;
  }
  return result;
}

// takes input and output file
// execute using "./a.out input1.txt svg1.svg"
int main(int argc, char *argv[]) {
  if (argc != 3) {
    cout << "usage: svg inputfile outputfile [input2 output2] ..." << endl;
    exit(EXIT_FAILURE);
  }
  processSVGFile(argv[1], argv[2]);

  return EXIT_SUCCESS;
}