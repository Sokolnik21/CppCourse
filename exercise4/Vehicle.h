#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>

#include "Person.h"

class Vehicle
{
public:
	Vehicle(const Person& _owner, int _mileage);
	virtual ~Vehicle() { }
	std::string description() const; /// zwraca napis z wszystkimi atrybutami (np. "wlasciciel: Jan Kowalski 1970, przebieg: 120000")
	virtual float powerKW() const { }
	bool write(std::ostream & os) const;
	bool load(std::istream & is);
	friend std::ostream& operator<<(std::ostream& stream, const Vehicle& v);
	friend std::istream& operator>>(std::istream& stream, Vehicle& v);
	virtual float getCapacity() const { }
	virtual std::string getBrand() const { }
protected:
	Person owner;
	int mileage;
};

#endif // VEHICLE_H
