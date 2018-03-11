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
  stream << "[" << p.x << ", " << p.y << "]";
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
  stream << "[[" << m.mxx << "][" << m.mxy << "]] ";
  stream << "[[" << m.mxy << "][" << m.myy << "]]";
  return stream;
}

Matrix operator-(Matrix a, Matrix b){
  Matrix result;
  result.mxx = a.mxx - b.mxx;
  result.myy = a.myy - b.myy;
  result.mxy = a.mxy - b.mxy;
  return result;
}

Matrix operator-=(Matrix& a, Matrix b) {
  a.mxx = a.mxx - b.mxx;
  a.myy = a.myy - b.myy;
  a.mxy = a.mxy - b.mxy;
  return a;
}

Matrix operator*(Matrix a, double s) {
  Matrix result;
  result.mxx = a.mxx * s;
  result.myy = a.myy * s;
  result.mxy = a.mxy * s;
  return result;
}
Matrix operator*(double s, Matrix a) {
  Matrix result;
  result.mxx = a.mxx * s;
  result.myy = a.myy * s;
  result.mxy = a.mxy * s;
  return result;
}
