/*
  File: Obiekty.cpp
*/

// https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm

#include "Obiekty.h"
#include <cstdlib>

using namespace std;

/**
 * Vector class
 */

/* Constructors */
Vector::Vector() {
  x = 0;
  y = 0;
}

Vector::Vector(double x, double y) {
  this -> x = x;
  this -> y = y;
}

// Vector::~Vector() {
//   cout << "Deleting point: ";
//   cout << this -> x << ", " << this -> y << endl;
// }

/* Stream */
ostream& operator<<(ostream& stream, Vector p) {
  stream << "[" << p.x << ", " << p.y << "]";
  return stream;
}

/* Arithmetic */
Vector Vector::operator+(Vector& b) {
  Vector result;
  result.x = this -> x + b.x;
  result.y = this -> y + b.y;
  return result;
}

/* Assignment */
Vector& Vector::operator+=(Vector& b) {
  this -> x = this -> x + b.x;
  this -> y = this -> y + b.y;
  return * this;
}

/* Increment */
/* Prefix */
Vector Vector::operator++() {
  x++;
  y++;
  return Vector(x, y);
}

/* Postfix */
Vector Vector::operator++(int) {
  // Save base value
  Vector base(x, y);
  // Decrement this object
  x++;
  y++;
  // Return old value
  return base;
}

/* Comparision */
bool Vector::operator==(Vector& b) {
  if(this -> x == b.x and this -> y == b.y)
    return true;
  return false;
}

/* Member access */
double& Vector::operator [](int n) {
  switch(n) {
    case 0: return x;
    case 1: return y;
    default: exit( -9000 );
  }
}

/**
 * Matrix class
 */

/* Constructors */
Matrix::Matrix() {
  mxx = 0;
  myy = 0;
  mxy = 0;
  myx = 0;
}

Matrix::Matrix(double mxx, double mxy, double myx, double myy) {
  this -> mxx = mxx;
  this -> myy = myy;
  this -> mxy = mxy;
  this -> myx = myx;
}

// Matrix::~Matrix() {
//   cout << "Deleting matrix: ";
//   cout << this -> mxx << ", " << this -> myy << ", " << this -> mxy << endl;
// }

/* Stream */
ostream& operator<<(ostream& stream, Matrix m) {
  stream << "[[" << m.mxx << "][" << m.mxy << "]] ";
  stream << "[[" << m.myx << "][" << m.myy << "]]";
  return stream;
}

Matrix operator*(Matrix a, double s) {
  Matrix result;
  result.mxx = a.mxx * s;
  result.myy = a.myy * s;
  result.mxy = a.mxy * s;
  result.myx = a.myx * s;
  return result;
}

Matrix operator*(double s, Matrix a) {
  Matrix result;
  result.mxx = a.mxx * s;
  result.myy = a.myy * s;
  result.mxy = a.mxy * s;
  result.myx = a.myx * s;
  return result;
}

Matrix Matrix::operator-() {
  Matrix result;
  result.mxx = -mxx;
  result.myy = -myy;
  result.mxy = -mxy;
  result.myx = -myx;
  return result;
}

/* Conversion */
/**
 How this matrix looks like
 [ mxx ][ mxy ]
 [ myx ][ myy ]
 (double)m returns determinant of the m
 */
Matrix::operator double() {
  return this -> mxx * this -> myy - this -> mxy * this -> myx;
}

// Multiply point with matrix
// 2x2 * 2x1 -> 2x1
Vector Matrix::operator*(Vector& v) {
  Vector result;
  result.x = v.x * this -> mxx + v.y * this -> mxy;
  result.y = v.x * this -> myx + v.y * this -> myy;
  return result;
}
