#include "Gold_Mine.h"
#include <iostream>
using namespace std;
int once2 = 0;

Gold_Mine::Gold_Mine():Game_Object('G')
{
	state = 'f';
	amount = 100;
  //Cart_Point location; //not sure if needed because called in .h file
	cout << "	Gold_Mine default constructed" << endl;
} 

Gold_Mine::Gold_Mine(int inputId, Cart_Point inputLoc):Game_Object('G', inputId, inputLoc)
{
	state = 'f';
	amount = 100;
	cout << "	Gold_Mine constructed" << endl;
}

bool Gold_Mine::is_empty()
{
  if (amount == 0)
    return true;
  else
    return false;
}

double Gold_Mine::dig_gold(double amount_to_dig)
{
  if (amount >= amount_to_dig)
    {
      amount = amount - amount_to_dig;
      return amount_to_dig;
    }
  else 
    {
		double return_amount = amount;
		amount = 0;
		return return_amount;
    }
}

bool Gold_Mine::update()
{
  if (amount == 0 && once2 == 0)
    {
	  once2++;
      state = 'e';
      display_code = 'g';
      cout << "Gold_Mine has been depleted." << endl;
      return true;
    }
  else 
    return false;
}

void Gold_Mine::show_status()
{
  cout << "Gold_Mine status:";
  Game_Object::show_status();
  cout << amount << endl;
}

Gold_Mine::~Gold_Mine()
{
	cout << "	Gold_Mine destructed." << endl;
}

double Gold_Mine::get_gold_amount()
{
	return amount;
}

void Gold_Mine::save(ofstream& file)
{


}

void Gold_Mine::restore(ifstream& file, Model& model)
{

}