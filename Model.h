#pragma once
#ifndef MODEL_H
#define MODEL_H
#include <iostream>
#include "Game_Object.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Person.h"
#include "Miner.h"
#include "View.h"
#include "Soldier.h"
#include "Inspector.h"
#include <list>
#include "Input_Handling.h"
using namespace std;

class Model
{
	int time;
	list<Game_Object*> object_ptrs;
	list<Game_Object*> active_ptrs; //point to obj still alive
	list<Person*> person_ptrs;
	list<Town_Hall*> hall_ptrs;
	list<Gold_Mine*> mine_ptrs;

public:
	Model();
	~Model();
	Person * get_Person_ptr(int id);
	Gold_Mine * get_Gold_Mine_ptr(int id);
	Town_Hall * get_Town_Hall_ptr(int id);
	bool update();
	void display(View &view);
	void show_status();
	void handle_new_command(char type, int in_id, double x, double y);
	list<Gold_Mine*> get_Gold_Mine_list();
	void save(ofstream& file);
	void restore(ifstream& file);
};
#endif