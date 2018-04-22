#include "EngineVehicle.h"

EngineVehicle::EngineVehicle(const Person& _owner, int _mileage, float _capacity, int _powerKM)
  :
  Vehicle(_owner, _mileage),
  capacity(_capacity),
  powerKM(_powerKM)
{ }

float EngineVehicle::getCapacity() const {
  return capacity;
}

float EngineVehicle::powerKW() const {
  return powerKM * 1.4;
}
