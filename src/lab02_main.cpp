// lab02_main.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <array_list.h>
int main(int argc, char** argv)
{
	ssuds::ArrayList<int> ilist;
	ilist.append(42);
	ilist.append(43);
	ilist.append(44);
	ilist.prepend(41);
	ilist.prepend(40);

	for (int i = 0; i < ilist.size(); i++)
		std::cout << "ilist[" << i << "] = " << ilist.at(i) << "\n";

	// [40, 41, 42, 43, 44]
	ilist.append(40);
	ilist.append(43);
	ilist.append(99);
	ilist.append(43);
	ilist.append(98);
	// [40, 41, 42, 43, 44, 40, 43, 99, 43, 98]
	int test = ilist.find(43);			// Should return 3
	test = ilist.find(43, 4);			// Should return 6
	test = ilist.find(43, 7);			// Should return 8
	test = ilist.find(43, 9);			// Should return -1
	test = ilist.find(104);				// Should return -1


	ilist.output(std::cout);			// [40, 41, 42, 43, 44, 40, 43, 99, 43, 98]
	std::ofstream fout("test.txt");
	ilist.output(fout);

}