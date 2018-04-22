#include "Vehicle.h"

/*
  Funny fact:
    When in Person's constructor weren't default values for atributes then
    Vehicle's contructor (that uses reference to Person) throw errors.
 */
// Vehicle::Vehicle(const Person& _owner, int _mileage) {
//   owner = _owner;
//   mileage = _mileage;
// }

Vehicle::Vehicle(const Person& _owner, int _mileage)
  :
  owner(_owner),
  mileage(_mileage)
{ }

std::string Vehicle::description() const {
  std::string result;
  result = result + "Owner: " + owner.getName() + " " + owner.getSurname() + " " + std::to_string(owner.getBirthYear()) + "\n";
  result = result + "Mileage: " + std::to_string(mileage);
  return result;
}

bool Vehicle::write(std::ostream & os) const {
  // owner.write(os);
  os << owner << " " << mileage;
}

bool Vehicle::load(std::istream & is) {
  char sign;
  is >> owner >> mileage;
}

std::ostream& operator<<(std::ostream& stream, const Vehicle& v) {
  v.write(stream);
  return stream;
}

std::istream& operator>>(std::istream& stream, Vehicle& v) {
  v.load(stream);
  return stream;
}
