#include "Cart_Point.h"
#include <cmath>

Cart_Point::Cart_Point()
{
  x = 0.0;
  y = 0.0;
}

Cart_Point::Cart_Point(double inputx, double inputy)
{
  x = inputx;
  y = inputy;
}

double cart_distance(Cart_Point p1, Cart_Point p2)
{
  double distance;
  double xdistance;
  double ydistance;
  xdistance = pow((p1.x - p2.x), 2);
  ydistance = pow((p1.y - p2.y), 2);
  distance = sqrt(xdistance + ydistance);
  return distance;
}

ostream& operator<<(ostream& out, Cart_Point& point) 
{
  out << "(" << point.x << ", " << point.y << ")";
  return out;
}  

Cart_Point operator+(Cart_Point& p1, Cart_Point& p2)
{
  return Cart_Point(p1.x + p2.x, p1.y + p2.y);
}

Cart_Vector operator-(Cart_Point& p1, Cart_Point& p2)
{
  return Cart_Vector(p1.x - p2.x, p1.y - p2.y);
}
