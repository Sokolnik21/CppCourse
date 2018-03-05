/*
  File: Data.cpp
*/

#include "Data.h"
// #include <iostream> // Already definied in Data.h file
using namespace std;

int Data::years = 0;

Data::Data() {
  day = 1;
  month = 1;
  year = 2000;
  years += 2000;
}

Data::Data(int day, int month, int year) {
  if(month < 1 or month > 12) {
    this -> day = 1;
    this -> month = 1;
    this -> year = 2000;
    years += 2000;
  }
  else {
    this -> day = day;
    this -> month = month;
    this -> year = year;
    years += year;
  }
}

Data::~Data() {
  cout << "Deleting ";
  this -> describe();
}

int Data::getYear() {
  return year;
}

void Data::addOneYear() {
  year++;
}

bool Data::lowerThan(Data d) {
  return year < d.year ? true :
    month < d.month ? true :
    day < d.day ? true : false;
}

void Data::describe() {
  cout << day << "." << month << "." << year << endl;
}

void Data::write(ostream& stream) {
  stream << day << "-" << month << "-" << year;
}

void Data::load(istream& stream) {
  char sign;
  stream >> day >> sign >> month >> sign >> year;
}

ostream& operator<<(ostream& stream, Data d) {
  d.write(stream);
  return stream;
}

istream& operator>>(istream& stream, Data& d) {
  d.load(stream);
  return stream;
}
