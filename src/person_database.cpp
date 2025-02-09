// person_database.cpp

#include <person_database.h>
#include <person.h>
#include <string>
#include <fstream>
#include <iostream>

// constructor
PersonDatabase::PersonDatabase(std::string fname) {
	// initially have no data.
	my_array = nullptr;
	my_array_size = 0;
	my_file_name = fname;

	// open the file.
	std::ifstream fin(fname);

	// read through the file line by line
	int temp_id;
	std::string temp_fname, temp_lname;
	float temp_hourly_rate, monthly_salary;
	unsigned int temp_hours;

	std::string dollar;

	// ignore the first line
	fin.ignore(10000, '\n');

	while (fin >> temp_fname >> temp_lname >> temp_id >> dollar >> temp_hourly_rate >> temp_hours >> monthly_salary) {
		Person temp_person(temp_id, temp_fname, temp_lname);
		temp_person.set_hourly_rate(temp_hourly_rate);
		temp_person.set_hours_worked(temp_hours);
		add_person(temp_person);
	}

	// close the file.
	fin.close();
}

PersonDatabase::~PersonDatabase() {
	// write out all data to the file, my_file_name, in write mode.
	// free up any resources, deallocate my_array. watch for new's that happen
	// in add_person, remove_person. make sure that memory that's still allocated
	// is freed up.

	// open file, my_file_name, for writing.
	std::ofstream fout(my_file_name);
	if (fout.is_open()) {
		// output the entire database as a string.
		fout << PersonDatabase::to_string();
		// fout << "testing";
	}
	// close file.
	fout.close();

	// clear memory still allocated
	delete[] my_array;
	my_array = nullptr;
}



void PersonDatabase::add_person(Person p)
{
	for (int i = 0; i < my_array_size; i++) {
		// check if the id of the person being added already exists in the array
		if (p.get_id() == my_array[i].get_id()) {
			throw std::runtime_error("ID already exists in database!");
			return;
		}
	}
	// if nothing in the array, make an array of size 1 and put person p in the only spot.
	if (my_array_size == 0)
	{
		my_array = new Person[1];
		my_array[0] = p;
		my_array_size = 1;
		return;
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
		// make sure to add the new person to the last position.
		new_array[my_array_size] = p;
		// turn the new_array into my_array
		delete[] my_array;
		my_array = new_array;
		// increment my_array_size as a new person was added.
		my_array_size++;
	}
}

// remove a person.
bool PersonDatabase::remove_person(int id_number) {
	if (my_array_size == 0) {
		return false;
	}
	int remove_index = -1;
	// get the index of the person to remove
	for (int i = 0; i < my_array_size; i++) {
		if (my_array[i].get_id() == id_number) {
			remove_index = i;
			break;
		}
	}
	if (remove_index == -1) {
		// return false if the ID input isnt found
		return false;
	}
	// make a new array thats one smaller than current array size
	Person* new_array = new Person[my_array_size - 1];

	// copy all elements except the one to get rid of
	for (int i = 0, j = 0; i < my_array_size; i++) {
		if (i != remove_index) {
			new_array[j++] = my_array[i];
		}
	}
	delete[] my_array;
	my_array = new_array;
	// decrement array size since one person was removed
	my_array_size--;

	return true;
}

// return number of people as int.
int PersonDatabase::get_num_people() {
	return my_array_size;
}

// return database as a string.
std::string PersonDatabase::to_string() {
	std::string output = "= Name ======= ID ===== Hourly Wage == Hours Worked ====== Monthly Salary =\n";
	for (int i = 0; i < my_array_size; i++) {
		// print out each Person in the array, along with their data
		output += my_array[i].get_first_name() +
		" " + my_array[i].get_last_name() +
		"\t" + std::to_string(my_array[i].get_id()) +
		"\t$ " + std::to_string(my_array[i].get_hourly_rate()) +
		"\t   " + std::to_string(my_array[i].get_hours_worked()) + 
		"\t\t    " + std::to_string(my_array[i].calculate_wage()) + "\n";
	}
	return output;
}