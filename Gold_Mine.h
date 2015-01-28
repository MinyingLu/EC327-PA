#ifndef GOLD_MINE_H
#define GOLD_MINE_H
#include <iostream>
#include "Game_Object.h"
#include "Cart_Point.h"
using namespace std;

class Model;
class Gold_Mine:public Game_Object
{
  double amount;

 public:
  Gold_Mine();
  Gold_Mine(int inputId, Cart_Point inputLoc);
  bool is_empty();
  double dig_gold(double amount_to_dig = 35.0);
  bool update();
  void show_status();
  ~Gold_Mine();
  double get_gold_amount();
  void save(ofstream& file);
  void restore(ifstream& file, Model& model);
};
#endif
