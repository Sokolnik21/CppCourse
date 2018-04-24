#include "Data.h"
#include "Product.h"
#include "Stuff.h"
#include "StuffWithBail.h"
#include "Service.h"

#define QUANTITY 4

int main() {
  std::cout << "Preparation:" << std::endl;
  Data d(2005, 4, 5);
  Data d1(996, 12, 12);
  d.setYear(1937);
  std::cout << d << std::endl;

  std::cout << "\nArray of pointers:" << std::endl;
  Product * pTable[QUANTITY];

  /* Objects initialization */
  Product p("cheese", d);
  Stuff s("ham", d1, 10, 1, d);
  StuffWithBail sw("cucumber", d1, 10, 1, d, 120);
  Service sr("tomato", d, 20, 2);

  /* Passing object reference to table */
  pTable[0] = &p;
  pTable[1] = &s;
  pTable[2] = &sw;
  pTable[3] = &sr;

  std::cout << "description():" << std::endl;
  for(int i = 0; i < QUANTITY; i++)
    std::cout << pTable[i] -> description() << std::endl;

  std::cout << "priceToPay():" << std::endl;
  for(int i = 1; i < QUANTITY; i++)
    std::cout << pTable[i] -> priceToPay() << std::endl;

  return 0;
}
