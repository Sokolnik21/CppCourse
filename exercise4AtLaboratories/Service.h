#ifndef SERVICE_H
#define SERVICE_H

#include <string>
#include <iostream>

#include "Product.h"

namespace Cowboy {
  class Service : public Product {
  public:
    Service(const std::string& _name, const Data& _production, double _hourCost, double _hourQuan);
    float priceToPay() const;
    std::string description() const;
  protected:
    double hourCost;
    double hourQuan;
  };
}

#endif
