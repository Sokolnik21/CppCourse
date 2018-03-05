#include <iostream>
using namespace std;

#include "Data.h"

int main() {
  Data d1(1, 1, 1993);
  Data d2(11, 11);

  // Expected value: 11.11.2000
  d2.describe();

  // Expected value: true ( result != 0 )
  cout << d1.lowerThan(d2) << endl;

  Data d3(11, 20, 1998);
  // Expected value: 1.1.2000
  d3.describe();

  // Expected value: 1993
  cout << d1.getYear() << endl;

  d1.addOneYear();
  // Expected value: 1994
  cout << d1.getYear() << endl;

  Data d4;
  // Expected value: 1.1.2000
  d4.describe();

  // Expected value: 1993 + 2000 + 2000 + 2000 = 7993
  cout << Data::getYearsQuantity() << endl;

  Data d5;
  cin >> d5;
  cout << d5 << endl;
  return 0;
}
