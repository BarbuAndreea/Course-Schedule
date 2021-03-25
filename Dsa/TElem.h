#pragma once
#include <string>
#include <ostream>
#include <iostream>
using namespace std;

class TElem
{
private:
	string c_name;
	int c_hour;
public:
	TElem() {

	}
	~TElem() {

	}
	TElem(string name, int hour);
	string get_name();
	int get_hour();
	void set_name(string new_name);
	void set_hour(int new_hour);
	string get_string();
	bool operator<(TElem a);
	bool operator<=(TElem a);
	bool operator>=(TElem a);
	bool operator>(TElem a);
	bool operator==(TElem a);
};

