#ifndef OBJECTS_H
#define OBJECTS_H
/*
  File: Obiekty.h
*/

// GitGut
// http://en.cppreference.com/w/cpp/language/operators

#include <iostream>
using namespace std;

class Vector;

class Matrix {
public:
	/* Constructors */
	Matrix();
	Matrix(double, double, double, double);
	// ~Matrix();

	/* Stream */
	friend ostream& operator<<(ostream&, Matrix);

	// /* Arithmetic */
	friend Matrix operator*(Matrix a, double s);
	friend Matrix operator*(double s, Matrix a);

	/* Arithmetic */
	Matrix operator-();


	/* Conversion */
	/**
	 How this matrix looks like
	 [ mxx ][ mxy ]
	 [ myx ][ myy ]
	 (double)m returns determinant of the m
	 */
	operator double();

	// Multiply Matrix with Vector
	// 2x2 * 2x1 -> 2x1
	Vector operator*(Vector& v);

	// friend Vector Vector::operator*(Matrix& m);

private:
	double mxx, myy, mxy, myx;
};

class Vector {
public:
	/* Constructors */
	Vector();
	Vector(double, double);
	// ~Vector();

	/* Stream */
	friend ostream& operator<<(ostream&, Vector);

	/* Arithmetic */
	Vector operator+(Vector& b);

	/* Assignment */
	Vector& operator+=(Vector& b);

	/* Increment */
	/* Prefix */
	Vector operator++();
	/* Postfix */
	Vector operator++(int);

	/* Comparision */
	bool operator==(Vector& b);

	/* Member access */
	double& operator [](int n);

	friend Vector Matrix::operator*(Vector& v);


private:
  double x, y;
};

/**
 How this matrix looks like
 [ mxx ][ mxy ]
 [ myx ][ myy ]
 */



#endif
