#include <iostream>
using namespace std;

#include "Obiekty.h"

int main() {
  cout << "Initialization" << endl;
  Vector vNON_ZERO(1, 2);
  Matrix mNON_ZERO(1, 2, 3, 4);
  Vector vZERO;
  Matrix mZERO;
  cout << vNON_ZERO << endl;
  cout << vZERO << endl;
  cout << mNON_ZERO << endl;
  cout << mZERO << endl;
  cout << endl;

  cout << "Arithmetic operations" << endl;
  Vector v1(1, 2);
  Vector v2(3, 3);
  cout << v1 + v2 << endl;
  v1 += v2;
  cout << v1 << endl;
  cout << endl;

  Matrix m1(1, 2, 3, 4);
  double d(1.7);
  cout << m1 * d << endl;
  cout << d * m1 << endl;
  cout << endl;

  Vector v3(1, 2);
  Matrix m2(1, 2, 3, 4);
  cout << (m2 * v3) << endl;
  cout << endl;

  Vector v4(1, 2);
  cout << v4 << endl;
  cout << v4++ << endl;
  cout << v4 << endl;
  cout << ++v4 << endl;
  cout << v4 << endl;
  cout << endl;

  Matrix m3(1, 2, 3, 4);
  cout << -m3 << endl;
  cout << endl;

  cout << "Logical" << endl;
  Vector v5(1, 2);
  Vector v6(1, 2);
  Vector v7(1, 1);
  cout << (v5 == v6) << endl;
  cout << (v5 == v7) << endl;
  cout << endl;

  cout << "Table" << endl;
  Vector v8(1, 2);
  cout << v8[0] << endl;
  cout << v8[1] << endl;
  cout << endl;

  cout << "Determinant" << endl;
  Matrix m4(1, 2, 3, 4);
  cout << (double)m4 << endl;

  return 0;
}
