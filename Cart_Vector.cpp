#include "Cart_Vector.h"

Cart_Vector::Cart_Vector()
{
  x = 0.0;
  y = 0.0;
}

Cart_Vector::Cart_Vector(double inputx, double inputy)
{
  x = inputx;
  y = inputy;
}

ostream& operator<<(ostream& out, Cart_Vector& vector)
{
  out << "<" << vector.x << ", " << vector.y << ">";
  return out;
}

Cart_Vector operator*(Cart_Vector& vector, double d)
{
  return Cart_Vector(vector.x * d, vector.y * d);
}

Cart_Vector operator/(Cart_Vector& vector, double d)
{
  return Cart_Vector(vector.x/d, vector.y/d);
}
