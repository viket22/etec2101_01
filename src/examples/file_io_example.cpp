#include <iostream>
#include <string>
#include <fstream>		// Access to fstream, ofstream, ifstream

#define MAIN_NODE 1		// 0 = output, 1 = input
#define FNAME "../../media/test.txt"

int main(int argc, char** argv) {
#if MAIN_NODE == 0
	// std::ofstream fout;
	// fout.open("test.txt");

	int x = 42;
	int y = 3.1f;
	std::string s = "Hello World";
	std::ofstream fout(FNAME); // Have a connection to that file (makes
												// the file no matter what, or overwites it).

	fout << x << ":" << y << ":" << s;

	x++;
	y++;
	s = +"xxx";

	fout << "\n" << x << ":" << y << ":" << s;

	fout.close();
#else
	// Alternate main program (for input)
	std::ifstream fin(FNAME);
	if (!fin.is_open()) {
		std::cout << "Error opening file '" << FNAME << "'\n";
		return 1;
	}

	int x2;
	float y2;
	std::string s2;

	while (!fin.eof()) {
		fin >> x2;
		fin.ignore(1000, ':');
		fin >> y2;
		fin.ignore(1000, ':');
		std::getline(fin, s2);

		std::cout << "Values read in:\n\tx2=" << x2 << "\n\ty2=" << y2 << "\n\ts2=" << s2 << "\n";
	}
#endif

	return 0;
}