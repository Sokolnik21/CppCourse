#ifndef ENGINE_VEHICLE_H
#define ENGINE_VEHICLE_H

#include <string>
#include <iostream>

#include "Vehicle.h"

class EngineVehicle : public Vehicle {
public:
  EngineVehicle(const Person& _owner, int _mileage, float _capacity, int _powerKM);
  float getCapacity() const;
  float powerKW() const;
protected:
  float capacity;
  int powerKM;
};

#endif
