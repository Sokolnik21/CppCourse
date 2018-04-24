#include "Service.h"

Service::Service(const std::string& _name, const Data& _production, double _hourCost, double _hourQuan)
  :
  Product(_name, _production),
  hourCost(_hourCost),
  hourQuan(_hourQuan)
{ }

float Service::priceToPay() const {
  return hourCost * hourQuan;
}

std::string Service::description() const {
  std::string result;
  result = result + "Name: " + name + "\n";
  result = result + "Production date: " + std::to_string(production.getYear()) + "\n";
  result = result + "Hour cost: " + std::to_string(hourCost) + "\n";
  result = result + "Hour quan: " + std::to_string(hourQuan) + "\n";
  return result;
}
