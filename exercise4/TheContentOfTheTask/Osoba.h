#ifndef OSOBA_H
#define OSOBA_H

#include <string>
#include <iostream>

class Osoba
{
public:
	Osoba(const std::string& _imie, const std::string& _nazwisko, int _rok_ur);
	void ustawImie(const std::string& im);
	std::string pobierzImie() const;
	bool zapisz(std::ostream & os) const; /// zapisuje atrybuty do strumienia
	bool wczytaj(std::istream & is); /// wczytuje atrybuty ze strumienia
private:
	std::string imie;
	std::string nazwisko;
	int	rok_ur;
};

#endif // OSOBA_H
