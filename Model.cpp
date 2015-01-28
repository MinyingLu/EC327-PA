#include "Model.h"
#include "Inspector.h"

Model::Model()
{
	time = 0;
	person_ptrs.push_back(new Miner(1, Cart_Point(5, 1)));
	person_ptrs.push_back(new Miner(2, Cart_Point(10, 1)));
	person_ptrs.push_back(new Soldier(3, Cart_Point(5, 15)));
	person_ptrs.push_back(new Soldier(4, Cart_Point(10, 15)));
	person_ptrs.push_back(new Inspector(5, Cart_Point(5, 5)));
	mine_ptrs.push_back(new Gold_Mine(1, Cart_Point(1, 20)));
	mine_ptrs.push_back(new Gold_Mine(2, Cart_Point(10, 20)));
	hall_ptrs.push_back(new Town_Hall(1, Cart_Point(0, 0)));
	
	for(list<Person*>::iterator it = person_ptrs.begin(); it != person_ptrs.end(); ++it)
	{
		object_ptrs.push_back(*it);
	}
	for(list<Gold_Mine*>::iterator it = mine_ptrs.begin(); it != mine_ptrs.end(); ++it)
	{
		object_ptrs.push_back(*it);
	}
	for(list<Town_Hall*>::iterator it = hall_ptrs.begin(); it != hall_ptrs.end(); ++it)
	{
		object_ptrs.push_back(*it);
	}
	active_ptrs = object_ptrs;
	
	cout << "	Model default constructed." << endl;
}

Model::~Model()
{
	cout << "	Model destructed." << endl;
}

Person * Model::get_Person_ptr(int id)
{
	for(list<Person*>::iterator it = person_ptrs.begin(); it != person_ptrs.end(); ++it)
	{
		if ((*it)->get_id() == id) 
			return *it;
	}
	return NULL;
}

Gold_Mine * Model::get_Gold_Mine_ptr(int id)
{
	for(list<Gold_Mine*>::iterator it = mine_ptrs.begin(); it != mine_ptrs.end(); ++it)
	{
		if ((*it)->get_id() == id)
			return *it;
	}
	return NULL;
}

Town_Hall * Model::get_Town_Hall_ptr(int id)
{
	for(list<Town_Hall*>::iterator it = hall_ptrs.begin(); it != hall_ptrs.end(); ++it)
	{
		if ((*it)->get_id() == id)
			return *it;
	}
	return NULL;
}

bool Model::update()
{
	time++;
	bool update = false;
	for(list<Game_Object*>::iterator it = active_ptrs.begin(); it != active_ptrs.end(); ++it)
	{
		update = update || (*it)->update();
	}
	for(list<Game_Object*>::iterator it = active_ptrs.begin(); it != active_ptrs.end(); ++it)
	{
		if((*it)->is_alive() == false)
		{
			it = active_ptrs.erase(it);
			cout << "Dead object removed." << endl;
		}
	} 
	return update;
}

void Model::display(View &view)
{
	view.clear();
	for(list<Game_Object*>::iterator it = active_ptrs.begin(); it != active_ptrs.end(); ++it)
	{
		view.plot(*it);
	}
	view.draw();
}

void Model::show_status()
{
	cout << "Time: " << time << endl; 
	for(list<Game_Object*>::iterator it = object_ptrs.begin(); it != object_ptrs.end(); ++it)
		(*it)->show_status();
}

void Model::handle_new_command(char type, int in_id, double x, double y)
{
	bool g_is_valid = true;
	bool t_is_valid = true;
	bool m_is_valid = true;
	bool s_is_valid = true;
	bool i_is_valid = true;
	switch(type)
	{
	case 'g':
		for(list<Gold_Mine*>::iterator it = mine_ptrs.begin(); it != mine_ptrs.end(); ++it)
		{
			g_is_valid = g_is_valid && (in_id != (*it)->get_id());
		}
		if (g_is_valid)
		{
			mine_ptrs.push_back(new Gold_Mine(in_id, Cart_Point(x, y)));
			list<Gold_Mine*>::iterator g_it = mine_ptrs.end();
			--g_it;
			object_ptrs.push_back(*g_it);
			active_ptrs.push_back(*g_it);
		}
		break;
	case 't':
		for(list<Town_Hall*>::iterator it = hall_ptrs.begin(); it != hall_ptrs.end(); ++it)
		{
			t_is_valid = t_is_valid && (in_id != (*it)->get_id());
		}
		if(t_is_valid)
		{
			hall_ptrs.push_back(new Town_Hall(in_id, Cart_Point(x, y)));
			list<Town_Hall*>::iterator t_it = hall_ptrs.end();
			--t_it;
			object_ptrs.push_back(*t_it);
			active_ptrs.push_back(*t_it);
			break;
		}
	case 'm':
		for(list<Person*>::iterator it = person_ptrs.begin(); it != person_ptrs.end(); ++it)
		{
			m_is_valid = m_is_valid && (in_id != (*it)->get_id());
		}
		if(m_is_valid)
		{
			person_ptrs.push_back(new Miner(in_id, Cart_Point(x, y)));
			list<Person*>::iterator m_it = person_ptrs.end();
			--m_it;
			object_ptrs.push_back(*m_it);
			active_ptrs.push_back(*m_it);
			break;
		}
	case 's':
		for(list<Person*>::iterator it = person_ptrs.begin(); it != person_ptrs.end(); ++it)
		{
			s_is_valid = s_is_valid && (in_id != (*it)->get_id());
		}
		if(s_is_valid)
		{
			person_ptrs.push_back(new Soldier(in_id, Cart_Point(x, y)));
			list<Person*>::iterator s_it = person_ptrs.end();
			--s_it;
			object_ptrs.push_back(*s_it);
			active_ptrs.push_back(*s_it);
			break;
		}
	case 'i':
		for(list<Person*>::iterator it = person_ptrs.begin(); it != person_ptrs.end(); ++it)
		{
			i_is_valid = i_is_valid && (in_id != (*it)->get_id());
		}
		if(i_is_valid)
		{
			person_ptrs.push_back(new Inspector(in_id, Cart_Point(x, y)));
			list<Person*>::iterator i_it = person_ptrs.end();
			--i_it;
			object_ptrs.push_back(*i_it);
			active_ptrs.push_back(*i_it);
			break;
		}

	}
}

list<Gold_Mine*> Model::get_Gold_Mine_list()
{
	return mine_ptrs;
}
	
void save(ofstream& file)
{

}

void restore(ifstream& file)
{

}