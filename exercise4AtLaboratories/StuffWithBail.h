#ifndef STUFF_WITH_BAIL_H
#define STUFF_WITH_BAIL_H

#include <string>
#include <iostream>

#include "Stuff.h"

namespace Cowboy {
  class StuffWithBail : public Stuff {
  public:
    StuffWithBail(const std::string& _name, const Data& _production, double _price, double _tax, const Data& _until, double _bail);
    float priceToPay() const;
    std::string description() const;
  protected:
    double bail;
  };
}

#endif
