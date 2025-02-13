// lab01_main.cpp

#include <person_database.h>
#include <person.h>
#include <iostream>
#include <string>

#define MY_FNAME "../../media/person_data.txt"

int main(int argc, char** argv) {
	PersonDatabase PD(MY_FNAME);
	int user_input = 0;
	while(true){
		std::cout << "Welcome to the person database! Please choose an option (1, 2, 3, 4)\n1. Add a Person\n2. Remove a person\n";
		std::cout << "3. Print database\n4. Quit\n";
		std::cin >> user_input;
		// check if user inputs anything other than 1, 2, 3, or 4.
		if (user_input < 1 || user_input > 4 || std::cin.fail()) {
			std::cout << "Invalid input!\n";
			// clear error flag
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			continue;
		}
		// continue as long as there is no input from the user.
		if (user_input == 1) {
			std::string first_name, last_name = "";
			float hours_worked;
			int id = 0;
			float hourly_rate = 0.0;
			// prompt user for all data needed to add person to database.
			std::cout << "\nPlease enter the proper data for the person to be added.\nFirst Name: ";
			std::cin >> first_name;
			std::cout << "Last Name: ";
			std::cin >> last_name;
			std::cout << "Hourly rate: ";
			std::cin >> hourly_rate;
			std::cout << "Hours worked (Integer): ";
			std::cin >> hours_worked;
			std::floor(hours_worked);
			std::cout << "Personal ID: ";
			std::cin >> id;
			Person new_person(id, first_name, last_name);
			new_person.set_hourly_rate(hourly_rate);
			new_person.set_hours_worked(hours_worked);
			PD.add_person(new_person);
			std::cout << "\n--- Person added! Returning to main menu. ---\n\n";
			// reset user_input back to 0.
			user_input = 0;
		} 
		else if (user_input == 2) {
			int removed_id = 0;
			std::cout << "\nPlease enter an ID to remove: ";
			std::cin >> removed_id;
			PD.remove_person(removed_id);
			std::cout << "\n--- Person with ID '" << removed_id << "' removed! Returning to main menu. ---\n\n";
		}
		else if (user_input == 3) {
			std::cout << "\nPrinting...\n\n";
			// call print function
			std::string output = PD.to_string();
			std::cout << output << "\n";
		}
		else if (user_input == 4) {
			std::cout << "\nQuitting...\n\n";
			break;
		}
	}
	// compiler will call the destructor for PersonDatabase here.
	return 0;
}