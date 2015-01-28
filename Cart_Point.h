#ifndef CART_POINT_H
#define CART_POINT_H
#include <iostream>
#include "Cart_Vector.h"
using namespace std;

class Cart_Point
{
 public:
  double x;
  double y;

  Cart_Point();
  Cart_Point(double inputx, double inputy);
};

double cart_distance(Cart_Point p1, Cart_Point p2);
ostream& operator<<(ostream& out, Cart_Point& point);
Cart_Point operator+(Cart_Point& p1, Cart_Point& p2);
Cart_Vector operator-(Cart_Point& p1, Cart_Point& p2);

#endif
