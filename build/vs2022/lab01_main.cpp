// main.cpp

#include "person_database.h"

#define MY_FNAME "../../media/person_data.txt"

int main(int argc, char** argv) {
	PersonDatabase PD(MY_FNAME);

	return 0;	// The compiler will call the destructor for PersonDatabase for you here.
}