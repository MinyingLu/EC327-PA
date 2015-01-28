#include "Person.h"

Person::Person():Game_Object()
{
	speed = 5.0;
	health = 5;
	cout << "	Person default constructed." << endl;
}

Person::Person(char in_code):Game_Object(in_code) //??is this how you do it?
{
	speed = 5.0;
	health = 5;
	cout << "	Person constructed." << endl;
}

Person::Person(char in_code, int in_id, Cart_Point in_loc):Game_Object(in_code, in_id, in_loc) //??
{
	speed = 5.0;
	health = 5;
	cout << "	Person constructed." << endl;
}

void Person::stop()
{
	state = 's';
	cout << "Stopping " << Game_Object::get_id() << endl;
	cout << Game_Object::get_id()<< ": All right." << endl;
	//not net
}

bool Person::update_location()
{
	if (fabs(fabs(destination.x) - fabs(location.x)) <= fabs(delta.x) && fabs(fabs(destination.y) - fabs(location.y)) <= fabs(delta.y))
	{
		cout << display_code << get_id() << ": I'm here!" << endl;
		location = destination;
		return true;
	}
	else if (cart_distance(destination, location) == 0)
	{
		cout << display_code << get_id() << ": I'm here!" << endl;
		location = destination;
		return true;
	}
	else 
	{  
		cout << "location now: " << location << endl;
		cout << display_code << get_id() << ": step..." << endl;
		location.x = location.x + delta.x;
		location.y = location.y + delta.y;
		cout << "location now: " << location << endl;
		return false;
	}
}

void Person::setup_destination(Cart_Point dest)
{
	destination = dest;
	delta = (destination - location);
	delta = delta*(speed/cart_distance(destination, location));
}

void Person::start_moving(Cart_Point dest)
{
	if(is_alive())
	{
		setup_destination(dest);
		state = 'm';
		cout << "Moving " << get_id() << " to " << destination << endl;
		cout << display_code << get_id() << ": On my way." << endl;
	}
	else
		cout << "I am dead. I may move but you just cannot see me." << endl;
}

void Person::show_status()
{
	cout << display_code << get_id() << " at " << location;
}

Person::~Person()
{
	cout << "	Person destructed." << endl;
}

void Person::start_mining(Gold_Mine* inputMine, Town_Hall* inputHome)
{
	cout << "Sorry, I can't work a mine." << endl;
}

bool Person::is_alive()
{
	if(state == 'x')
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Person::take_hit(int attack_strength, Person *attacker_ptr)
{
	health = health - attack_strength;
	if (health <= 3)
	{
		switch (display_code)
		{
		case 'M': 
			display_code = 'm';
			break;
		case 'S':
			display_code = 's';
			break;
		case 'I':
			display_code = 'i';
			break;
		default:
			break;
		}
	}
	if (health <= 0)
	{
		cout << display_code << get_id() << ": Arrggh! I am dying." << endl;
		state = 'x';
	}
	else {
		cout << display_code << get_id() << ": Ouch!" << endl;
	}
	Cart_Vector escape_vec;
	escape_vec = location - attacker_ptr->get_location();
	escape_vec = escape_vec * 1.5;
	switch (display_code)
	{
	case 'm':
		cout << display_code << get_id() << ": I don't wanna fight!" << endl; 
		start_moving(Cart_Point(location.x + escape_vec.x, location.y + escape_vec.y)); 
		break;
	case 'i':
		cout << display_code << get_id() << ": I don't wanna fight!" << endl; 
		start_moving(Cart_Point(location.x + escape_vec.x, location.y + escape_vec.y));
		break;
	}
}

void Person::start_attack(Person * target)
{
	cout << "I can't attack." <<endl;
}


void Person::start_inspecting(Model& model)
{
	cout << "Sorry, I can't inspect." << endl;
}

void Person::save(ofstream& file)
{


}

void Person::restore(ifstream& file, Model& model)
{

}
