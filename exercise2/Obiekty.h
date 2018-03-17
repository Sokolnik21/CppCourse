#ifndef OBJECTS_H
#define OBJECTS_H
/*
  File: Obiekty.h
*/

// GitGut
// http://en.cppreference.com/w/cpp/language/operators

#include <iostream>
using namespace std;

class Matrix;

class Point {
public:
	/* Constructors */
	Point();
	Point(double, double);
	// ~Point();

	/* Stream */
	friend ostream& operator<<(ostream&, Point);

	/* Arithmetic */
	Point operator-();

	/* Member access */
	double& operator [](int n);

	// Multiply point with matrix
	// 1x2 * 2x2 -> 1x2
	Point operator*(Matrix& m);

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
	/* Constructors */
	Matrix();
	Matrix(double, double, double);
	// ~Matrix();

	/* Stream */
	friend ostream& operator<<(ostream&, Matrix);

	/* Arithmetic */
	Matrix operator-(Matrix& b);
	friend Matrix operator*(Matrix a, double s);
	friend Matrix operator*(double s, Matrix a);

	/* Assignment */
	Matrix& operator-=(Matrix& b);


	/* Decrement */
	/* Prefix */
	Matrix operator--();
	/* Postfix */
	Matrix operator--(int);

	/* Conversion */
	/**
	 How this matrix looks like
	 [ mxx ][ mxy ]
	 [ mxy ][ myy ]
	 (double)m returns determinant of the m
	 */
	operator double();

	/* Comparision */
	bool operator<(Matrix& b);

	friend Point Point::operator*(Matrix& m);

private:
	double mxx, myy, mxy;
};

#endif
