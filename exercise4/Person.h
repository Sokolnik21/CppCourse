#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person
{
public:
	// Person(const std::string& _name = "Tommy", const std::string& _surname = "Wiseau", int _birth_year = 2003);
	Person(const std::string& _name, const std::string& _surname, int _birth_year);
	void setName(const std::string& name);
	std::string getName() const;
	std::string getSurname() const;
	int getBirthYear() const;
	bool write(std::ostream & os) const; /// zapisuje atrybuty do strumienia
	bool load(std::istream & is); /// wczytuje atrybuty ze strumienia
	friend std::ostream& operator<<(std::ostream& stream, const Person& p);
	friend std::istream& operator>>(std::istream& stream, Person& p);
private:
	std::string name;
	std::string surname;
	int	birth_year;
};

#endif // PERSON_H
