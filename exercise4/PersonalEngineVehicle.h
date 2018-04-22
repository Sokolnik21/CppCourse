#ifndef PERSONAL_ENGINE_VEHICLE_H
#define PERSONAL_ENGINE_VEHICLE_H

#include <string>
#include <iostream>

#include "EngineVehicle.h"

class PersonalEngineVehicle : public EngineVehicle {
public:
  PersonalEngineVehicle(const Person& _owner, int _mileage, float _capacity, int _powerKM, const std::string& _brand);
  std::string getBrand() const;
protected:
  std::string brand;
};

#endif
