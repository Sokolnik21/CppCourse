#include "Data.h"
using namespace Cowboy;

Data::Data(int _year, int _month, int _day)
:
year(_year),
month(_month),
day(_day)
{ }

void Data::setYear(int _year) {
  year = _year;
}

int Data::getYear() const {
  return year;
}

bool Data::write(std::ostream & os) const {
  os << year << " " << month << " " << day;
}

bool Data::load(std::istream & is) {
  is >> year >> month >> day;
}

namespace Cowboy {
  std::ostream& operator<<(std::ostream& stream, const Data& d) {
    d.write(stream);
    return stream;
  }

  std::istream& operator>>(std::istream& stream, Data& d) {
    d.load(stream);
    return stream;
  }
}
