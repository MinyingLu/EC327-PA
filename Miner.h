#ifndef MINER_H
#define MINER_H
#include <iostream>
#include <math.h>
#include "Person.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
using namespace std;

class Model;
class Miner:public Person
{
	double amount;
	Gold_Mine* mine;
	Town_Hall* home;

public:
	Miner();
	Miner(int inputx, Cart_Point inputLoc);
	bool update();
	void start_mining(Gold_Mine* inputMine, Town_Hall* inputHome);
	void show_status();
	~Miner();
	void restore(ifstream& file, Model& model);
	void save(ofstream& file);
};
#endif
