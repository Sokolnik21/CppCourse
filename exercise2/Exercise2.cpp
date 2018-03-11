#include <iostream>
using namespace std;

#include "Obiekty.h"

int main() {
  Point p;
  cout << p << endl;

  Matrix m1(5,5,5);
  Matrix m2(2,2,2);
  cout << m1 - m2 << endl;
  m1-=m2;
  cout << m1 << endl;
  double b = 0.7;
  cout << m1 * b << endl;

  return 0;
}
