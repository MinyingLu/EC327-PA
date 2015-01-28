#include "Inspector.h"

Inspector::Inspector():Person('I')
{
	name = "Clouseau";
	Gold_Mine* mine = NULL;
	cout << "	Inspector default constructed." << endl;
}

Inspector::Inspector(int in_id, Cart_Point in_loc):Person('I', in_id, in_loc)
{
	name = "Clouseau";
	Gold_Mine* mine = NULL;
	cout << "	Inspector constructed." << endl;
}

void Inspector::start_inspecting(Model& in_model)
{
	not_inspected = in_model.get_Gold_Mine_list();
	state = 'o';
	cout << display_code << get_id() << " starting to inspect." << endl;
}

bool Inspector::update()
{
	//only when inspector arrives at a destination 
	Cart_Point dest;
	double distance = 100.0;
	double temp_distance;
	bool u;
	//list<Gold_Mine*>::iterator it; 
	switch (state)
	{
	case 's':  //stop
		break;
	case 'c': //complete trip
		state = 's';
		return false;
		break;
	case 'o': //outbound moving
		for(list<Gold_Mine*>::iterator o_it = not_inspected.begin(); o_it != not_inspected.end(); ++o_it)
		{
			dest = (*o_it)->get_location();
			temp_distance = cart_distance(dest, location);
			if(temp_distance < distance)
			{
				distance = temp_distance;
				mine = *o_it;
			}
		}
		setup_destination(mine->get_location());
		distance = 100.0;
		if (update_location()) {
			been_inspected.push(mine);
			not_inspected.remove(mine);
			cout << "size of been_inspected now: " << been_inspected.size() << endl;
			state = 'g';
			return true;
		}
		else 
		  return false;
		break;
	case 'g': //outbound inspecting
		cout << display_code << get_id() << ": This mine contains " << mine->get_gold_amount() << " of gold." << endl;
		if(!not_inspected.empty()) {
			cout << "Going to next mine." << endl;
			state = 'o';	
			//return false;
		}
		else{
			cout << "Heading back." << endl;
			state = 'i';
			//return false;
		}
		break;
	case 'i': //inbound moving
		mine = been_inspected.top();
		setup_destination(mine->get_location());
		//cout << "location now: " << location << endl;
		if(update_location()) {
			been_inspected.pop();
			state = 'd';
			return true;
		}
		else {
			return false;
		}
		break;
	case 'd': //inbound inspecting
		cout << display_code << get_id() << ": This mine contains " << mine->get_gold_amount() << " of gold." << endl;
		if(!been_inspected.empty())
			state = 'i';
		else
			state = 'c';
		break;
	case 'x':  //don't know what now 
		//
		return false;
		break;
	}
	return false;
}

void Inspector::show_status()
{
	cout << "Inspector status: ";
	Person::show_status();
	switch (state)
	{
	case 's':
		cout << "   Stopped." << endl;
		break;
	case 'c':
	    cout << "	Inspection complete." << endl; //finish outbound and inbound
		break;
	case 'o':
		cout << "   Outbound inspecting." << endl; //basically moving to next mine	outbound phase
		break;
	case 'g':
		cout << "   Doing outbound inspection." << endl; //will return how many gold a mine contains
		break;
	case 'i':
		cout << "   Inbound inspecting." << endl; //moving, inbound phase
		break;
	case 'd':
		cout << "   Doing inbound inspection" << endl; // inspecting. 
		break;
	case 'x':
		cout << " is dead." << endl;
	}
}

void Inspector::save(ofstream& file)
{


}

void Inspector::restore(ifstream& file, Model& model)
{

}