#ifndef BICYCLE_H
#define BICYCLE_H

#include <string>
#include <iostream>

#include "Vehicle.h"

class Bicycle : public Vehicle {
public:
  Bicycle(const Person& _owner, int _mileage, bool _amateur);
  float powerKW() const;
protected:
  bool amateur;
};

#endif
