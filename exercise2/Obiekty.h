#ifndef OBJECTS_H
#define OBJECTS_H
/*
  File: Obiekty.h
*/

#include <iostream>
using namespace std;

class Point {
public:
	Point();
	Point(double, double);
	// ~Point();

	friend ostream& operator<<(ostream&, Point);
	friend istream& operator>>(istream&, Point&);

private:
  double x, y;
};

/**
 How this matrix looks like
 [ mxx ][ mxy ]
 [ mxy ][ myy ]
 */

class Matrix {
public:
	Matrix();
	Matrix(double, double, double);
	// ~Matrix();

	friend ostream& operator<<(ostream&, Matrix);
	friend istream& operator>>(istream&, Matrix&);

private:
  double mxx, myy, mxy;
};

#endif
