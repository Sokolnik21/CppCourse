#include <iostream>
using namespace std;

#include "Point.h"

int main() {
  // Point p1(1, 1, 1);
  // Point p2(2, 2, 2);
  // cout << "Distace between p1 and p2: " << p1.distance(p2) << endl;
  // p2.describe();
  //
  // cout << Point::getCounter() << endl;
  //
  // Point p3;
  // cout << p3;
  // cin >> p3;
  // cout << p3 << endl;

  Point d1(1, 1, 1);
  cout << "Expected value: 1, 1, 1\n";
  d1.describe();

  Point d2(11, 11);
  cout << "Expected value: 11.11.0\n";
  d2.describe();

  cout << "Expected value: 14.1774\n";
  cout << d1.distance(d2) << endl;

  cout << "Expected value: 1\n";
  cout << d1.getX() << endl;

  d1.setX(3.14);
  cout << "Expected value: 3.14\n";
  cout << d1.getX() << endl;

  cout << "Expected value: d1, d2 -> 2\n";
  cout << Point::getCounter() << endl;

  Point d3;
  cin >> d3;
  cout << d3 << endl;

  cout << "Expected value: d1, d2, d3 -> 3\n";
  cout << Point::getCounter() << endl;
  return 0;
}
