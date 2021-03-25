// Dsa.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "SortedSet.h"
#include "Ui.h"
#include <iostream>
#include "Tests.h"

int main()
{
	RunTests();
	SortedSet SS;
	Ui ui(SS);
	ui.run();
	system("pause");
	return 0;
}
