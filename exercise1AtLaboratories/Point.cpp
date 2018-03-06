/*
  File: Point.cpp
*/

#include <iomanip>
#include <math.h>
#include "Point.h"
using namespace std;

int Point::counter = 0;

Point::Point() {
  x = y = z = 0;
  counter++;
}

Point::Point(float x, float y, float z) {
  this -> x = x;
  this -> y = y;
  this -> z = z;
  counter++;
}

// Point::~Point() {
//   cout << "Deleting ";
//   this -> describe();
// }

float Point::getX() {
  return x;
}

void Point::setX(float x) {
  this -> x = x;
}

float Point::distance(Point p) {
  float xVal = p.x - x;
  float yVal = p.y - y;
  float zVal = p.z - z;
  return sqrt(xVal * xVal + yVal * yVal + zVal * zVal);
}

void Point::describe() {
  cout << x << ", " << y << ", " << z << endl;
}

void Point::write(ostream& stream) {
  stream << "[" << fixed << setprecision(4) << x << ", " << y << ", " << z << "]";
}

void Point::load(istream& stream) {
  char sign;
  stream >> sign >> x >> sign >> y >> sign >> z >> sign;
}

ostream& operator<<(ostream& stream, Point p) {
  p.write(stream);
  return stream;
}

istream& operator>>(istream& stream, Point& p) {
  p.load(stream);
  return stream;
}
