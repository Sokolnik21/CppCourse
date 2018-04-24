#include "Product.h"

Product::Product(const std::string& _name, const Data& _production)
:
name(_name),
production(_production)
{ }

std::string Product::description() const {
  std::string result;
  result = result + "Name: " + name + "\n";
  result = result + "Production date: " + std::to_string(production.getYear()) + "\n";
  return result;
}

bool Product::write(std::ostream & os) const {
  os << name << " " << production;
}

bool Product::load(std::istream & is) {
  is >> name >> production;
}

namespace Cowboy {
  std::ostream& operator<<(std::ostream& stream, const Product& p) {
    p.write(stream);
    return stream;
  }

  std::istream& operator>>(std::istream& stream, Product& p) {
    p.load(stream);
    return stream;
  }
}
