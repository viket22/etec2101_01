// person_database.h

#pragma once
#include <person.h>

// Person Database class: Create a PersonDatabase object that holds an array of Person objects.

class PersonDatabase
{
private:
	// will eventually hold an array of Person objects.
	Person* my_array;
	// the size of my_array array.
	unsigned int my_array_size;
public:
	// this method should open the file, reading in one person per line.
	// ex: 101 John Doe 42 13.5
	// ex: 102 Jane Doe 48 14.5
	std::string my_file_name = " ";
	PersonDatabase(std::string fname);

	// adds a person.
	void add_person(Person p);
	// removes a person.
	bool remove_person(int id_number);
	// returns number of people in database as int.
	int get_num_people();
	// returns database as a string.
	std::string to_string();

	~PersonDatabase();
};