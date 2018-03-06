#ifndef POINT_H
#define POINT_H
/*
  File: Point.h
*/

#include <iostream>
using namespace std;

class Point {
public:
	Point();
	Point(float, float, float = 0);
	// ~Point();
  float getX();
  void setX(float);
  float distance(Point);
  void describe();
	static int getCounter() { return counter; }

	void write(ostream&);
	void load(istream&);

	friend ostream& operator<<(ostream&, Point);
	friend istream& operator>>(istream&, Point&);

private:
  float x, y, z;
	static int counter;
};

#endif
