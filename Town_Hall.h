#ifndef TOWN_HALL_H
#define TOWN_HALL_H
#include <iostream>
#include "Game_Object.h"
#include "Cart_Point.h"
using namespace std;

class Model;
class Town_Hall:public Game_Object
{
  double amount;

public:
  Town_Hall();
  Town_Hall(int inputId, Cart_Point inputLoc);
  void deposit_gold(double deposit_amout);
  bool update();
  void show_status();
  ~Town_Hall();
  void save(ofstream& file);
  void restore(ifstream& file, Model& model);
};

#endif
