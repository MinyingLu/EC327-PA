#ifndef CART_VECTOR_H
#define CART_VECTOR_H
#include <iostream>
using namespace std;

class Cart_Vector
{
 public:
  double x;
  double y;

  Cart_Vector();
  Cart_Vector(double inputx, double inputy);
};

ostream& operator<<(ostream& out, Cart_Vector& vector);
Cart_Vector operator*(Cart_Vector& v1, double d);
Cart_Vector operator/(Cart_Vector& v1, double d);

#endif

