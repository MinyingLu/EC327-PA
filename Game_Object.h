#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include <iostream>
#include "Cart_Point.h"
using namespace std;

class Model;
class Game_Object
{
public:
	Game_Object();
	Game_Object(char in_code);
	Game_Object(char in_code, int in_id, Cart_Point in_loc);
	Cart_Point get_location();
	int get_id();
	virtual void show_status();
	virtual ~Game_Object();
	virtual void drawself(char * ptr);
	virtual bool update() = 0; //pure virtual
	virtual bool is_alive();
	virtual void save(ofstream& file);
	virtual void restore(ifstream& file, Model& model);

protected:
	Cart_Point location;
	char display_code;
	char state;

private:
	int id_num;
};
#endif