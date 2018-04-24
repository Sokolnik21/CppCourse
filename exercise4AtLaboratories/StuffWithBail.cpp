#include "StuffWithBail.h"

StuffWithBail::StuffWithBail(const std::string& _name, const Data& _production, double _price, double _tax, const Data& _until, double _bail)
  :
  Stuff(_name, _production, _price, _tax, _until),
  bail(_bail)
{ }

float StuffWithBail::priceToPay() const {
  return price + price * tax + bail;
}

std::string StuffWithBail::description() const {
  std::string result;
  result = result + "Name: " + name + "\n";
  result = result + "Production date: " + std::to_string(production.getYear()) + "\n";
  result = result + "Price: " + std::to_string(price) + "\n";
  result = result + "Tax " + std::to_string(tax) + "\n";
  result = result + "Until date " + std::to_string(until.getYear()) + "\n";
  result = result + "Bail: " + std::to_string(bail) + "\n";
  return result;
}
