#include "Model.h"
#include "Input_Handling.h"
#include "Game_Command.h"
#include <iostream>
using namespace std;

int main()
{
	View view;
	Model model;
	model.show_status();
	model.display(view);

	char command = 'z';
	char trash[256];
	int id1, id2, id3;
	double x, y;
	char type;

while (command != 'q')
{
	cout << "enter command: ";
	cin >> command;
	try
	{
	switch (command)
	{
	case 'm':
		id1 = get_int();
		x = get_double();
		y = get_double();
		move(model, id1, x, y, view); 
		break;
	case 'w':
		id1 = get_int();
		id2 = get_int();
		id3 = get_int();
		work(model, id1, id2, id3, view);
		break;
	case 's':
		id1 = get_int();
		stop(model, id1, view);
		break;
	case 'n':
		type = get_new_command();
		id1 = get_int();
		x = get_double();
		y = get_double();
		new_command(model, type, id1, x, y, view);
		break;
	case 'i':
		id1 = get_int();
		inspect(model, id1, view);
		break;
	case 'g':  
		go(model, view);  //some how get into infinitei loop not sure how to get in
		break;
	case 'r':  	
		run(model, view);  //might have the same problem as go
		break;
	case 'a':
		id1 = get_int();
		id2 = get_int();
		attack(model, id1, id2, view);
		break;
	case 'q':
		break;
	default:
		//cin.clear();
		//cin.getline(trash, 256);
		throw Invalid_Input("Please enter correct command");
	}
	} 
	catch(Invalid_Input& except)
	{
		cout << "Invalid input - " << except.msg_ptr << endl;
		//action to be taken if the input is wrong
		cin.clear();
		cin.getline(trash, 256);
	}
}
}
