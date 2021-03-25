#pragma once
#include "Ui.h"

void Ui::run()
{
	int first_h, last_h;
	cout << "What time does your work schedule start? ";
	cin>> first_h;
	cout << "What time does it end? ";
	cin >> last_h;
	if (last_h < first_h)
		cout << "The start time of the work schedule cannot be longer than the end time of the work schedule!\n ";
	else if (last_h < 1 && last_h>24 || first_h < 1 && first_h>24)
		cout << "Incorrect time. The time must between 1 and 24.";
	else
	{
		while (1) {
			string cmd;
			cout << endl;
			this->menu();
			cout << endl;
			cout << "Please enter an option: ";
			cin >> cmd;
			if (cmd == "1") {
				string name, k;
				int hour;
				cout << "Enter the course name: ";
				getline(cin, k);
				getline(cin, name);
				cout << "Enter the course start time: ";
				cin >> hour;
				try {
					this->add_u(name, hour, first_h, last_h);
				}
				catch (exception& e)
				{
					cout << e.what() << endl;
				}
			}
			else if (cmd == "2") {
				string name, k;
				int hour;
				cout << "Enter the course name: ";
				getline(cin, k);
				getline(cin, name);
				cout << "Enter the course start time: ";
				cin >> hour;
				try {
					this->remove_u(name, hour);
				}
				catch (exception& e)
				{
					cout << e.what() << endl;
				}
			}
			else if (cmd == "3")
				this->display_u();

			else if (cmd == "4")
				break;
			else
				cout << "\nUnknown option\n";
		}
	}
}

void Ui::menu()
{
	cout << "MENU: ";
	cout << "\n1. Add a new course.\n";
	cout << "2. Remove a course.\n";
	cout << "3. Display all the courses.\n";
	cout << "4. Exit.\n";
}

void Ui::add_u(string name, int hour, int firt_hour, int last_hour)
{
	TElem e;
	e.set_name(name);
	e.set_hour(hour);
	if (hour < firt_hour || hour > last_hour)
		throw std::exception("This time is not in your work schedule!");
	try {
		sortS.add(e);
	}
	catch (exception e) {
		cout << e.what() << endl;

	}
}

void Ui::remove_u(string name, int hour)
{
	TElem e;
	e.set_name(name);
	e.set_hour(hour);
	if (sortS.search(e) == NULL)
		throw std::exception("It does not exists!");
	else
		sortS.remove(e);
}

void Ui::display_u()
{
	cout << endl;
	cout << "// SCHEDULE //" << endl;
	Iterator iter = sortS.iterator();
	while (iter.valid() == true) {
		cout << "Time: " << iter.get_current().get_hour() << " --> " << iter.get_current().get_name() << endl;
		iter.next();
	}
	cout << endl;
}

