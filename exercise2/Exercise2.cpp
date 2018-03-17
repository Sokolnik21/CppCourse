#include <iostream>
using namespace std;

#include "Obiekty.h"

int main() {
  Point p(1, 2);
  cout << p << endl;
  cout << -p << endl;

  Matrix m1(5,5,5);
  Matrix m2(2,2,2);
  cout << m1 - m2 << endl;
  m1-=m2;
  cout << m1 << endl;
  double b = 0.7;
  cout << m1 * b << endl;
  cout << m1 << endl;
  cout << --m1 << endl;
  cout << m1 << endl;
  cout << m1-- << endl;
  cout << m1 << endl;
  cout << (double)m1 << endl;

  Matrix m3(5,5,1);
  Matrix m4(2,2,2);
  cout << (m3 < m4) << endl;
  cout << (m4 < m3) << endl;

  Point p5(1, 2);
  cout << p5[0] << endl;
  cout << p5[1] << endl;

  p5[1] = 2.7;
  cout << p5 << endl;

  Point p1(2, 2);
  Point p2 = p1 * m2;
  cout << p2 << endl;

  return 0;
}
