#ifndef STUFF_H
#define STUFF_H

#include <string>
#include <iostream>

#include "Product.h"

namespace Cowboy {
  class Stuff : public Product {
  public:
    Stuff(const std::string& _name, const Data& _production, double _price, double _tax, const Data& _until);
    Data getUntil() const;
    float priceToPay() const;
    std::string description() const;
  protected:
    double price;
    double tax;
    Data until;
  };
}

#endif
