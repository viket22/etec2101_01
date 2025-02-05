// person.h
#pragma once
#include <string>

class Person
{
	// By default attributes and methods are private (can only be access in the class)
	// Good rule of thumb: make attributes private and have methods to indirectly access
	// them public.
private:
	// ATTRIBUTES - A variable that all instances of the class have
	int id;
	std::string first_name;
	std::string last_name;
	float hourly_rate;
	unsigned int hours_worked;
public:
	Person();

	Person(int starting_id, std::string start_fname, std::string start_lname);

	// GETTER methods
	int get_id();
	std::string get_first_name();
	std::string get_last_name();
	float get_hourly_rate();
	unsigned int get_hours_worked();

	// SETTER methods
	void set_hourly_rate(float new_rate);
	void set_hours_worked(unsigned int new_hours);

	// METHOD - A function that instances of the class can call
	float calculate_wage();

	// Destructor (Called when an instance is about to be destroyed)
	// Always has the name of the class, only one.
	~Person();
};

