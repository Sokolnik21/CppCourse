/*
  File: Obiekty.cpp
*/

// https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm

#include "Obiekty.h"
#include <cstdlib>

using namespace std;

/**
 * Point class
 */

/* Constructors */
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

/* Stream */
ostream& operator<<(ostream& stream, Point p) {
  stream << "[" << p.x << ", " << p.y << "]";
  return stream;
}

/* Arithmetic */
Point Point::operator-() {
  Point result;
  result.x = -x;
  result.y = -y;
  return result;
}

/* Member access */
double& Point::operator [](int n) {
  switch(n) {
    case 0: return x;
    case 1: return y;
    default: exit( -9000 );
  }
}

// Multiply point with matrix
// 1x2 * 2x2 -> 1x2
Point Point::operator*(Matrix& m) {
  Point result;
  result.x = this -> x * m.mxx + this -> y * m.mxy;
  result.y = this -> x * m.mxy + this -> y * m.myy;
  return result;
}

/**
 * Matrix class
 */

/* Constructors */
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

/* Stream */
ostream& operator<<(ostream& stream, Matrix m) {
  stream << "[[" << m.mxx << "][" << m.mxy << "]] ";
  stream << "[[" << m.mxy << "][" << m.myy << "]]";
  return stream;
}

/* Arithmetic */
Matrix Matrix::operator-(Matrix& b) {
  Matrix result;
  result.mxx = this -> mxx - b.mxx;
  result.myy = this -> myy - b.myy;
  result.mxy = this -> mxy - b.mxy;
  return result;
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

/* Assignment */
Matrix& Matrix::operator-=(Matrix& b) {
  this -> mxx = this -> mxx - b.mxx;
  this -> myy = this -> myy - b.myy;
  this -> mxy = this -> mxy - b.mxy;
  return * this;
}

/* Decrement */
/* Prefix */
Matrix Matrix::operator--() {
  mxx--;
  myy--;
  mxy--;
  return Matrix(mxx, myy, mxy);
}

/* Postfix */
Matrix Matrix::operator--(int) {
  // Save base value
  Matrix base(mxx, myy, mxy);
  // Decrement this object
  mxx--;
  myy--;
  mxy--;
  // Return old value
  return base;
}

/* Conversion */
/**
 How this matrix looks like
 [ mxx ][ mxy ]
 [ mxy ][ myy ]
 (double)m returns determinant of the m
 */
Matrix::operator double() {
  return this -> mxx * this -> myy - this -> mxy * this -> mxy;
}

/* Comparision */
bool Matrix::operator<(Matrix& b) {
  return *this < (double)b;
}
