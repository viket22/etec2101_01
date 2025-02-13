// Examples of using cin/cout and file input/output, stringstreams
#include <iostream>
#include <string>

int main(int argc, char** argv) {
	int x = 42;
	float y;
	std::string s;

	std::cout << "Enter an integer value for x: ";
	std::cin >> x;
	if (std::cin.fail()) {
		std::cout << "Invalid value, setting x to -1.\n";
		x = -1;
		// Note: cin is in an 'error state', we need to tell cin it's ok.
		std::cin.clear();
		// Note2: the \n is stil in the buffer, we don't want it there.
		// Note3: Make sure to do clear before ignoring newline.
		std::cin.ignore(1, '\n');	// Ignore up to 1 char until \n is seen.
	}

	// If we just want a single word
	//std::cout << "Enter a string value for s (no whitespace): ";
	//std::cin >> s;
	std::cin.ignore(100, '\n');

	// If we want any kind of text
	// Note4: Since we have some input already, there's likely a newline
	// still in the buffer.
	std::cout << "Enter a string value for s: ";
	std::getline(std::cin, s);

	std::cout << "Enter a float value for y: ";
	std::cin >> y;

	std::cout << "\nx is: " << x << "\ny is: " << y << "\ns is: " << s;


	return 0;
}