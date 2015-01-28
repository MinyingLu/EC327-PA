#include "Soldier.h"

Soldier::Soldier():Person()
{
	attack_strength = 2;
	range = 2.0;
	Person * target;
	cout << "	Soldier default constructed." << endl;
}

Soldier::Soldier(int in_id, Cart_Point in_loc):Person('S', in_id, in_loc)
{
	attack_strength = 2;
	range = 2.0;
	Person * target;
	cout << "	Soldier constructed." << endl;
}

void Soldier::start_attack(Person * in_target)
{
	if(is_alive())
	{
		target = in_target;
		Cart_Point target_loc = target->get_location();
		Cart_Vector distance_vec = location - target_loc;
		double distance = sqrt(fabs(pow(distance_vec.x, 2)-pow(distance_vec.y, 2)));
		if( distance <= range )//distance smaller than range
		{
			cout << display_code << get_id() << ": Attacking." << endl;
			state = 'a';
		}
		else
			cout << "Target is out of range." << endl;
	}
	else
		cout << "I am dead. You do not have the ability to summon the undead." << endl;
}

bool Soldier::update()
{
	switch (state)
	{
	case 'x':
		return false;
		break;
	case 's':
		return false;
		break;
	case 'm':
		if (update_location()) 
		{
			state = 's';
			return true;
		}
		else 
			return false;
		break;
	case 'a':
		Cart_Point target_loc = target->get_location();
		Cart_Vector distance_vec = location - target_loc;
		double distance = sqrt(fabs(pow(distance_vec.x, 2)-pow(distance_vec.y, 2)));
		if(distance > range)
		{
			cout << "Target is out of range." << endl;
			state = 's';
			return true;
		}
		else
		{
			if(target->is_alive()) 
			{
				cout << display_code << get_id() << ": Take that!" << endl;
				target->take_hit(attack_strength, this); 
				return false;
			}
			else
			{
				cout << display_code << get_id() << ": I win!" << endl;
				state = 's';
				return true;
			}
		}
		break;
	}
}

void Soldier::show_status()
{
	cout << "Soldier status: ";
	Person::show_status();
	switch (state)
	{
	case 'x':
		cout << " is dead." << endl;
		break;
	case 's':
		cout << "	Stopped." << endl;
		break;
	case 'm':
		if (is_alive()) 
		{
			//do move action
		}
		else 
			cout << "I am dead. blablabla" << endl;
		break;
	case 'a':
		cout << "	Attacking" << endl;
		break;
	}
}

Soldier::~Soldier()
{
	cout << "	Soldier destructed." << endl;
}

void Soldier::save(ofstream& file)
{


}

void Soldier::restore(ifstream& file, Model& model)
{

}

void Soldier::take_hit(int attack_strength, Person * attacker_ptr)
{
	Person::take_hit(attack_strength, attacker_ptr);
	//start_attack(attacker_ptr);
	target = attacker_ptr;
	if(is_alive())
		state = 'a';
	//TO DO: "Attacking" 
}