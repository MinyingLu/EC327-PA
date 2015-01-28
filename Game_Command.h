#include "View.h"
#include "Model.h"
#include "Input_Handling.h"
#include <iostream>
using namespace std;

void move(Model &model, int in_id, double x, double y, View &view);
void work(Model &model, int p_id, int g_id, int t_id, View &view);
void stop(Model &model, int p_id, View &view);
void go(Model &model, View &view);
void run(Model &model, View &view);
void attack(Model &model, int, int, View &view);
void new_command(Model &model, char, int, double, double, View &view);
void inspect(Model &model, int, View &view);

int get_int();
double get_double();
char get_new_command();

