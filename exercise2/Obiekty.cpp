/*
  File: Obiekty.cpp
*/

#include "Obiekty.h"

using namespace std;

/**
 * Point class
 */

Point::Point() {
  x = 0;
  y = 0;
}

Point::Point(double x, double y) {
  this -> x = x;
  this -> y = y;
}

// Point::~Point() {
//   cout << "Deleting point: ";
//   cout << this -> x << ", " << this -> y << endl;
// }

ostream& operator<<(ostream& stream, Point p) {
  stream << p.x << "," << p.y;
  return stream;
}

istream& operator>>(istream& stream, Point& p) {
  char sign;
  stream >> p.x >> sign >> p.y;
  return stream;
}

/**
 * Matrix class
 */

Matrix::Matrix() {
  mxx = 0;
  myy = 0;
  mxy = 0;
}

Matrix::Matrix(double mxx, double myy, double mxy) {
  this -> mxx = mxx;
  this -> myy = myy;
  this -> mxy = mxy;
}

// Matrix::~Matrix() {
//   cout << "Deleting matrix: ";
//   cout << this -> mxx << ", " << this -> myy << ", " << this -> mxy << endl;
// }

ostream& operator<<(ostream& stream, Matrix m) {
  stream << m.mxx << "," << m.myy << "," << m.mxy;
  return stream;
}

istream& operator>>(istream& stream, Matrix& m) {
  char sign;
  stream >> m.mxx >> sign >> m.myy >> sign >> m.mxy;
  return stream;
}
