#include "Town_Hall.h"
#include "Game_Object.h"
#include <iostream>
using namespace std;
int once = 0;

Town_Hall::Town_Hall():Game_Object('t')
{
	state = 'o';
	amount = 0;
	Cart_Point location; //not sure if needed
	cout << "	Town_Hall default constructed" << endl;
}

Town_Hall::Town_Hall(int inputId, Cart_Point inputLoc):Game_Object('t', inputId, inputLoc)
{
	state = 'o';
	amount = 0;
	cout << "	Town_Hall constructed" << endl;
}

void Town_Hall::deposit_gold(double deposit_amount)
{
  amount = amount + deposit_amount;
}

bool Town_Hall::update()
{
  if (amount >= 50 && once == 0) {
	  once++;
      state = 'u';
	  display_code = 'T';
	  cout << display_code << Game_Object::get_id() << " has been upgraded." << endl;
      return true;
    }
  else 
      return false;
}

void Town_Hall::show_status()
{
  cout << "Town_Hall status:"; 
  Game_Object::show_status();
  cout << amount << " of gold.";
 if (amount >= 50)
     cout << "   Upgraded" << endl;
 else 
	 cout << "   Not yet upgraded" << endl;
}

Town_Hall::~Town_Hall()
{
	cout << "	Town_Hall destructed." << endl;
}

void Town_Hall::save(ofstream& file)
{


}

void Town_Hall::restore(ifstream& file, Model& model)
{

}