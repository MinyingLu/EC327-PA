#include "Miner.h"

Miner::Miner():Person('M')
{
	amount = 0;
    mine = NULL;
	home = NULL;
	cout << "	Miner default constructed." << endl;
}

Miner::Miner(int in_id, Cart_Point in_loc):Person('M', in_id, in_loc) 
{
	amount = 0;
    mine = NULL;
	home = NULL;
	cout << "	Miner constructed" << endl;
}

void Miner::show_status() 
{
	cout << "Miner status: ";
	Person::show_status();
	switch (state)
	{
	case 's':
		cout << "   Stopped." << endl;
		break;
	case 'm':
	    /*cout << "   Moving at speed " << speed << " to " << destination;
	    cout << "   <X, Y> amount on each step are " << delta; */
		break;
	case 'o':
		cout << "   Outbound to a mine." << endl;
		break;
	case 'g':
		cout << "   Getting gold from mine" << endl;
		break;
	case 'i':
		cout << "   Inbound to home with load: " << amount << endl;
		break;
	case 'd':
		cout << "   Depositing gold." << endl;
		break;
	case 'x':
		cout << " is dead." << endl;
	}
}

bool Miner::update()
{
	switch (state)
	{
	case 's':
		break;
	case 'm':
		if (update_location()) {
			state = 's';
			return true;
		}
		else 
		  return false;
		break;
	case 'o':
		setup_destination(mine->get_location());
		if (update_location()) {
			state = 'g';
			return true;
		}
		else 
		  return false;
		break;
	case 'g':
	    amount = mine->dig_gold();
		cout << display_code << get_id() << ": Got " << amount << " gold." << endl;
		setup_destination(home->get_location()); 
		state = 'i';
		return true;
		break;
	case 'i':
		if(update_location()) {
			state = 'd';
			return true;
		}
		break;
	case 'd':
		cout << display_code << get_id() << ": Deposit " << amount << " of gold." << endl;
		home->deposit_gold(amount); 
		amount = 0;
		if (mine->is_empty()) {
			state = 's';
			cout << display_code << get_id() << ": More work?" << endl;
			return true;
		}
		else {
			state = 'o';
			cout << display_code << get_id() << ": Going back for more." << endl;
			return true;
		}
		break;
	case 'x':
		//
		return false;
		break;
	}
	return false;
}

void Miner::start_mining(Gold_Mine* inputMine, Town_Hall* inputHome)
{
	if(is_alive())
	{
		mine = inputMine;
		home = inputHome;
		state = 'o';
		cout << "Miner " << get_id() << " mining at Gold_Mine " << mine->get_id() << " and depositing at Town_Hall " << home->get_id() << endl;
		cout << display_code << get_id() << ": Yes, my lord." << endl;
	}
	else
		cout << "I am dead. Are you kidding me? Ask a zombie to work!?!?" << endl;
}

Miner::~Miner()
{
	cout << "	Miner destructed." << endl;
}

void Miner::save(ofstream& file)
{


}

void Miner::restore(ifstream& file, Model& model)
{

}