#include "Game_Command.h"


void move(Model &model, int p_id, double x, double y, View &view)
{
  Cart_Point dest;
  dest.x = x;
  dest.y = y;
  Person * person;
  person = model.get_Person_ptr(p_id);
  person->start_moving(dest);
  model.display(view);
}

void work(Model &model, int p_id, int g_id, int t_id, View &view)
{
	Person * person;
	Gold_Mine * mine;
	Town_Hall * town;
	person = model.get_Person_ptr(p_id);
	mine = model.get_Gold_Mine_ptr(g_id);
	town = model.get_Town_Hall_ptr(t_id);
	person->start_mining(mine, town); //to fix
	model.display(view);
}

void stop(Model &model, int p_id, View &view)
{
	Person * person;
	person = model.get_Person_ptr(p_id);
	person->stop();
	model.display(view);
}

void go(Model &model, View &view)
{
	cout << "Advancing one tick." << endl;
	model.update();
	model.show_status();
	model.display(view);
}

void run(Model &model, View &view)
{
	cout << "Advancing to next event." << endl;
	for (int i = 0; i < 5; i++) 
	{
		if(model.update())
			break;
    }
	model.show_status();
	model.display(view);
}

void attack(Model &model, int f_id1, int f_id2, View &view)
{
	Person * p1;
	Person * p2;
	p1 = model.get_Person_ptr(f_id1);
	p2 = model.get_Person_ptr(f_id2);
	p1->start_attack(p2);
	model.display(view);
}

int get_int() 
{
	int i;
	if(!(cin >> i))
		throw Invalid_Input("Was expecting an integer");
	return i;
}

double get_double()
{
	double i;
	if(!(cin >> i))
		throw Invalid_Input("Was expecting a double");
	return i;
}

char get_new_command()
{
	char ch;
	if(!(cin >> ch))
		throw Invalid_Input("Was expecting a character");
	else
	{
		if(ch != 'g' && ch != 't' && ch != 'm' && ch != 's' && ch != 'i')
			throw Invalid_Input("Please enter valid command");
		return ch;
	}
}

void new_command(Model &model, char type, int in_id, double x, double y, View &view)
{
	model.handle_new_command(type, in_id, x, y);
	model.display(view);
}

void inspect(Model &model, int id1, View &view)
{
	Person * person;
	person = model.get_Person_ptr(id1);
	person->start_inspecting(model);
	model.display(view);
}