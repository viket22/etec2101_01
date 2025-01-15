#include <person.h>		// "" used for local files, <> using for libraries built in
#include <string>

// We're providing the BODY / DEFINITION of the method declared in the person.h file
float Person::calculate_wage() {
	/* In any(non - static) method, we have access to all attributes for
	   this instance, our job in this method is to tell the compiler how
	   to calculate a wage using our attributes.
	*/
	return hourly_rate * hours_worked;
}