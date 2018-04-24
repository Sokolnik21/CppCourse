#include "Stuff.h"

Stuff::Stuff(const std::string& _name, const Data& _production, double _price, double _tax, const Data& _until)
  :
  Product(_name, _production),
  price(_price),
  tax(_tax),
  until(_until)
{ }

Data Stuff::getUntil() const {
  return until;
}

float Stuff::priceToPay() const {
  return price + price * tax;
}

std::string Stuff::description() const {
  std::string result;
  result = result + "Name: " + name + "\n";
  result = result + "Production date: " + std::to_string(production.getYear()) + "\n";
  result = result + "Price: " + std::to_string(price) + "\n";
  result = result + "Tax " + std::to_string(tax) + "\n";
  result = result + "Until date " + std::to_string(until.getYear()) + "\n";
  return result;
}
