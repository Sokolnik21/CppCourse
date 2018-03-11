#ifndef OBJECTS_H
#define OBJECTS_H
/*
  File: Obiekty.h
*/

// GitGut
// http://en.cppreference.com/w/cpp/language/operators

#include <iostream>
using namespace std;

class Point {
public:
	Point();
	Point(double, double);
	// ~Point();

	friend ostream& operator<<(ostream&, Point);

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
	friend Matrix operator-(Matrix a, Matrix b);
	friend Matrix operator-=(Matrix& a, Matrix b);
	friend Matrix operator*(Matrix a, double s);
	friend Matrix operator*(double s, Matrix a);

private:
  double mxx, myy, mxy;
};

#endif
