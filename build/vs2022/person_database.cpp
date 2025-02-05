// person_database.cpp
#include "person_database.h"
#include <person.h>
#include <string>
#include <fstream>
#include "person_database.h"


PersonDatabase::PersonDatabase(std::string fname)
{
	// Initialize attributes
	my_array = nullptr;			// This means we (right now) don't have data
	my_array_size = 0;

	// Open the file
	my_file_name = fname;
	std::ifstream fin(fname);
	if (fin.is_open()) {
		// Read through the file, line-by-line
		while (true)
		{
			// Get a line's worth of data
			int temp_id;
			std::string temp_fname, temp_lname;
			float temp_hourly_rate;
			unsigned int temp_hours;

			// <code to read into those>

			// <code to decide if its read properly>
			if (!fin.eof())
			{
				Person temp_person(temp_id, temp_fname, temp_lname);
				temp_person.set_hourly_rate(temp_hourly_rate);
				temp_person.set_hours_worked(temp_hours);

				// Use our add_person to do the hard work
				add_person(temp_person);
			}
		}
	}


	// Close the file
	fin.close();
}

PersonDatabase::~PersonDatabase() {
	// Write out all data to the file (my_file_name) in write mode.

	// Free up any resources - deallocate my_array. Watch for "new's" that happen
	// (here in add_person, remove_person) -- we need to make sure that memory
	// that's still allocated is freed up.

	std::ofstream fout(my_file_name);
	if (fout.is_open()) {
		fout << PersonDatabase::to_string();
		
	}
	fout.close();

}



void PersonDatabase::add_person(Person p)
{
	for (int i = 0; i < my_array_size; i++) {
		// check if the id of the person being added already exists in the array
		if (p.get_id() == my_array[i].get_id()) {
			std::runtime_error("Person already exists in the database!");
		}
	}
	// if nothing in the array, make an array of size 1 and put person p in the only spot.
	if (my_array_size == 0)
	{
		my_array = new Person[1];
		my_array[0] = p;
		my_array_size = 1;
	}

	// if array is already there, make a Person array of my_array_size + 1,
	// copy data from existing array in the new array, then free the
	// old array.
	else
	{
		Person* new_array = new Person[my_array_size + 1];
		for (int i = 0; i < my_array_size; i++) {
			new_array[i] = my_array[i];
		}
		delete[] my_array;
		my_array = new_array;
	}
}

// remove a person.
void PersonDatabase::remove_person(Person p) {
	// create a new array that is 1 smaller
	Person* new_array = new Person[my_array_size - 1];
	int removed_id = p.get_id();
	// copy people in array before the one being removed
	for (int i = 0; i < removed_id; i++) {
		new_array[i] = my_array[i];
	}
	// copy people in array after the one being removed
	for (int i = removed_id + 1; i < my_array_size; i++) {
		new_array[i - 1] = my_array[i];
	}
	delete[] my_array;
	my_array = new_array;
}

// return number of people as int.
int PersonDatabase::get_num_people() {
	return 0;
}

// return database as a string.
std::string PersonDatabase::to_string() {
	std::string output = "";
	for (int i = 0; i < my_array_size; i++) {
		// print out each Person in the array, along with their data
		output + my_array[i].get_first_name() + my_array[i].get_last_name() +
			"\t" + std::to_string(my_array[i].get_id()) + "\t$" + std::to_string(my_array[i].get_hourly_rate()) +
				std::to_string(my_array[i].get_hours_worked()) + "\n";
	}
	return output;
}