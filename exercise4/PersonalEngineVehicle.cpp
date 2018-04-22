#include "PersonalEngineVehicle.h"

PersonalEngineVehicle::PersonalEngineVehicle(const Person& _owner, int _mileage, float _capacity, int _powerKM, const std::string& _brand)
  :
  EngineVehicle(_owner, _mileage, _capacity, _powerKM),
  brand(_brand)
{ }

std::string PersonalEngineVehicle::getBrand() const {
  return brand;
}
