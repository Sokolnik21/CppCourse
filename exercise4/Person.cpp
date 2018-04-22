#include "Person.h"

// Person::Person(const std::string& _name, const std::string& _surname, int _birth_year) {
//   name = _name;
//   surname = _surname;
//   birth_year = _birth_year;
// }

Person::Person(const std::string& _name, const std::string& _surname, int _birth_year)
  :
  name(_name),
  surname(_surname),
  birth_year(_birth_year)
{ }

void Person::setName(const std::string& _name) {
  name = _name;
}

std::string Person::getName() const {
  return name;
}

std::string Person::getSurname() const {
  return surname;
}

int Person::getBirthYear() const {
  return birth_year;
}

bool Person::write(std::ostream & os) const {
  os << name << " " << surname << " " << birth_year;
}

bool Person::load(std::istream & is) {
  is >> name >> surname >> birth_year;
}

std::ostream& operator<<(std::ostream& stream, const Person& p) {
  p.write(stream);
  return stream;
}

std::istream& operator>>(std::istream& stream, Person& p) {
  p.load(stream);
  return stream;
}
