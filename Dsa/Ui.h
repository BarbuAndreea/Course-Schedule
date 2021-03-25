#pragma once
#include "SortedSet.h"
#include "TElem.h"
#include <iostream>
#include <istream>
#include <sstream>
using namespace std;
class Ui
{
private:
	SortedSet sortS;
public:
	Ui(SortedSet ss) : sortS(ss){}
	~Ui(){}
	void run();
	void menu();
	void add_u(string name, int hour, int first_hour, int last_hour);
	void remove_u(string name, int hour);
	void display_u();
};

