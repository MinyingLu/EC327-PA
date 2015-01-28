#pragma once
#ifndef INSPECTOR_H
#define INSPECTOR_H
#include "Person.h"
#include "Gold_Mine.h"
#include "Model.h"
#include <iostream>
#include <list>
#include <string>
#include <stack>
using namespace std;

class Model;
class Inspector: public Person
{
private:
	string name; 
	Gold_Mine* mine;
	//Model model;
	list<Gold_Mine*> not_inspected;
	stack<Gold_Mine*> been_inspected; //change to stack 
	stack<double> amount_list;  //change to stack 
public:
	Inspector();
	Inspector(int in_id, Cart_Point in_loc);
	void start_inspecting(Model& model);
	bool update();
	void show_status();
	void save(ofstream& file);
	void restore(ifstream& file, Model& model);
};

#endif
