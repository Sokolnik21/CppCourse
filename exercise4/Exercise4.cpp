#include "Vehicle.h"
#include "Person.h"
#include "Bicycle.h"
#include "EngineVehicle.h"
#include "PersonalEngineVehicle.h"

#define QUANTITY 4

/**
  To do (after this exercise)
    - learn about const usage in functions (how it influences program, etc.)
  Why?
    in cpp "const" actually matters
 */

int main() {
  std::cout << "Preparation:" << std::endl;
  Person p("Jan", "Nowak", 1937);
  p.setName("Edmund");
  std::cout << p << std::endl;

  std::cout << "\nArray of pointers:" << std::endl;
  Vehicle * vTable[QUANTITY];

  /* Objects initialization */
  Vehicle v(p, 12000);
  Bicycle b(p, 100, false);
  EngineVehicle e(p, 700000, 2, 107);
  PersonalEngineVehicle pe(p, 5400, 2, 107, "Lada");

  /* Passing object reference to table */
  vTable[0] = &v;
  vTable[1] = &b;
  vTable[2] = &e;
  vTable[3] = &pe;

  std::cout << "description():" << std::endl;
  for(int i = 0; i < QUANTITY; i++)
    std::cout << vTable[i] -> description() << std::endl;

  std::cout << "powerKW():" << std::endl;
  for(int i = 1; i < QUANTITY; i++)
    std::cout << vTable[i] -> powerKW() << std::endl;

  std::cout << "getCapacity():" << std::endl;
  for(int i = 2; i < QUANTITY; i++)
    std::cout << vTable[i] -> getCapacity() << std::endl;

  std::cout << "getBrand():" << std::endl;
  std::cout << vTable[QUANTITY - 1] -> getBrand() << std::endl;

  return 0;
}
