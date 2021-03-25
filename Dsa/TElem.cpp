#include "TElem.h"

TElem::TElem(string name, int hour)
{
	c_name = name;
	c_hour = hour;
}

string TElem::get_name()
{
	return c_name;
}

int TElem::get_hour()
{
	return c_hour;
}

void TElem::set_name(string new_name)
{
	c_name = new_name;
}

void TElem::set_hour(int new_hour)
{
	c_hour = new_hour;
}

string TElem::get_string()
{
	string str;
	str = c_name + " course --- at ";
	str+= c_hour + " o'clock.\n";
	return str;
}

bool TElem::operator<(TElem a)
{
	if (this->c_hour < a.c_hour)
		return true;
	return false;
}

bool TElem::operator<=(TElem a)
{
	if (this->c_hour <= a.c_hour)
		return true;
	return false;
}

bool TElem::operator>=(TElem a)
{
	if (this->c_hour >= a.c_hour)
		return true;
	return false;
}

bool TElem::operator>(TElem a)
{
	if (this->c_hour > a.c_hour)
		return true;
	return false;
}

bool TElem::operator==(TElem a)
{
	if (this->c_hour == a.c_hour)
		return true;
	return false;
}
