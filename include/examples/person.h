/* #pragma once is a short-hand for the ifndef, define, then endif
	either are ok to use, the purpose of both is to prevent the compiler
	from over seeing the declaration of this class twice, which causes an error.
*/

#ifndef _PERSON_H_
#define _PERSON_H_
#include <string>

class Person
{
	// By default attributes and methods are private (can only be access in the class)
	// Good rule of thumb: make attributes private and have methods to indirectly access
	// them public.
public:
	// METHOD - A function that instances of the class can call
	float calculate_wage();
	// ATTRIBUTES - A variable that all instances of the class have
	int id;
	std::string first_name;
	std::string last_name;
	float hourly_rate;
	unsigned int hours_worked;
};

#endif