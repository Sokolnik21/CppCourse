#ifndef DATA_H
#define DATA_H
/*
  File: Data.h
*/

#include <iostream>
using namespace std;

class Data {
public:
	Data();
	Data(int, int, int = 2000);
	~Data();
  int getYear();
  void addOneYear();
  bool lowerThan(Data);
  void describe();
	static int getYearsQuantity() { return years; }

	void write(ostream&);
	void load(istream&);

	friend ostream& operator<<(ostream&, Data);
	friend istream& operator>>(istream&, Data&);

private:
  int day, month, year;
	static int years;
};

#endif
