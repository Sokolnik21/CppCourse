#ifndef POJAZD_H
#define POJAZD_H

#include <string>
#include <iostream>

#include "Osoba.h"

class Pojazd
{
public:
	Pojazd(const Osoba& _wlasciciel, int _przebieg);
	~Pojazd();
	std::string opis() const; /// zwraca napis z wszystkimi atrybutami (np. "wlasciciel: Jan Kowalski 1970, przebieg: 120000")
	float mocKW() const;
	bool zapisz(std::ostream & os) const;
	bool wczytaj(std::istream & is);
protected:
	Osoba wlasciciel;
	int przebieg;
};

#endif // POJAZD_H
