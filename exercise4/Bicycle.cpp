#include "Bicycle.h"

Bicycle::Bicycle(const Person& _owner, int _mileage, bool _amateur)
  :
  Vehicle(_owner, _mileage),
  amateur(_amateur)
{ }

float Bicycle::powerKW() const {
  if(amateur)
    return 0.3;
  else
    return 0.4;
}
