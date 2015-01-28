#include "Game_Object.h"

Game_Object::Game_Object()
{
	display_code = ' ';
	state = 's';
	id_num = 0;
	Cart_Point location;
	cout << "	Game_Object default constructed" << endl;
}

Game_Object::Game_Object(char in_code)
{
	display_code = in_code;
	state = 's';
	id_num = 0;
	Cart_Point location;
	cout << "	Game_Object constructed." << endl;
}

Game_Object::Game_Object(char in_code, int in_id, Cart_Point in_loc)
{
	display_code = in_code;
	id_num = in_id;
	location = in_loc;
	state = 's';
	cout << "	Game_Object constructed." << endl;
}

Cart_Point Game_Object::get_location()
{
	return location;
}

int Game_Object::get_id()
{
	return id_num;
}

void Game_Object::show_status()
{
	cout << display_code << id_num << " at location " << location << " contains ";

}

void Game_Object::drawself(char * ptr)
{
	ptr[0] = display_code;
	ptr[1] = 48+id_num;
}

Game_Object::~Game_Object()
{
	cout << "	Game_Object descturcted." << endl;
}

bool Game_Object::is_alive()
{
	return true;
}

void Game_Object::save(ofstream& file)
{


}

void Game_Object::restore(ifstream& file, Model& model)
{

}