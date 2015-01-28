#ifndef PERSON_H
#define PERSON_H
#include "Game_Object.h"
#include "Cart_Vector.h"
#include "Cart_Point.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include <iostream>
#include <cmath>
using namespace std; 

class Model; 
class Person:public Game_Object
{
public:
	Person();
	Person(char in_code);
	Person(char in_code, int in_id, Cart_Point in_loc);
	void start_moving(Cart_Point dest);
	void stop();
	void show_status();
	virtual ~Person();
	virtual void start_mining(Gold_Mine* inputMine, Town_Hall* inputHome);
	bool is_alive();
	virtual void take_hit(int attack_strength, Person * attacker_ptr);
	virtual void start_attack(Person * target);
	virtual void start_inspecting(Model& model);
	void save(ofstream& file);
	void restore(ifstream& file, Model& model);

protected:
	bool update_location();
	void setup_destination(Cart_Point dest);

private:
	double speed;
	Cart_Point destination;
	Cart_Vector delta;
	int health;
};
#endif