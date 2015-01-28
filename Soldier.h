#ifndef SOLDIER_H
#define SOLDIER_H
#include <iostream>
#include "Person.h"
using namespace std;

class Model;
class Soldier: public Person
{
	int attack_strength;
	double range;
	Person * target;
public:
	Soldier();
	Soldier(int in_id, Cart_Point in_loc);
	void start_attack(Person * in_target);
	bool update();
	void show_status();
	~Soldier();
	void save(ofstream& file);
	void restore(ifstream& file, Model& model);
	void take_hit(int , Person*);
};
#endif