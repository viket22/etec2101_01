// lab02_main.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <array_list.h>
int main(int argc, char** argv)
{
	std::cout << "===== Append & Prepend Test =====\n";
	// create new ArrayList object called ilist
	ssuds::ArrayList<int> ilist;
	ilist.append(100);
	ilist.append(101);
	ilist.append(102);
	ilist.append(103);
	ilist.append(104);
	ilist.prepend(100);
	ilist.prepend(101);
	ilist.prepend(102);
	ilist.prepend(103);
	ilist.prepend(104);
	
	for (int i = 0; i < ilist.size(); i++)
		std::cout << "ilist[" << i << "] = " << ilist.at(i) << "\n";		// Output: [104,103,102,101,100,100,101,102,103,104]
	
	std::cout << "\n===== Remove & Remove All Test =====\n\n";
	
	ilist.remove(0); // will remove value at index 0 which is 104.

	ilist.remove_all(100); // will remove all occurences of value 100.

	for (int i = 0; i < ilist.size(); i++)
		std::cout << "ilist[" << i << "] = " << ilist.at(i) << "\n";	// Output: [103,102,101,101,102,103,104]
	
	std::cout << "\n===== Find Test =====\n\n";
	
	int test1 = ilist.find(101); // should return 2.

	int test2 = ilist.find(102, 3); // should return 4.

	std::cout << "'Find' test 1: " << test1 << "\n'Find' test 2: " << test2 << "\n";	// Output: 'Find' test 1: 2
																						//		   'Find' test 2: 4

	std::cout << "\n===== Insert Test =====\n\n";

	// these will insert a '1' between every number
	ilist.insert(1, 0);
	ilist.insert(1, 2);
	ilist.insert(1, 4);
	ilist.insert(1, 6);
	ilist.insert(1, 8);
	ilist.insert(1, 10);
	ilist.insert(1, 12);
	ilist.insert(1, 14);

	for (int i = 0; i < ilist.size(); i++)
		std::cout << "ilist[" << i << "] = " << ilist.at(i) << "\n";	// Output: [1,103,1,102,1,101,1,101,1,102,1,103,1,104,1]

	std::cout << "\n===== Size, Capacity Test & Reserve Test =====\n\n";

	std::cout << "Array Size: " << ilist.size() << "\nArray Capacity (before reserve): " << ilist.capacity() << "\n";

	ilist.reserve(50);
	
	std::cout << "Array Capacity (after reserve): " << ilist.capacity() << "\n";

	std::cout << "\n===== ostream Test =====\n\n";

	ilist.output(std::cout);											// Output: [1,103,1,102,1,101,1,101,1,102,1,103,1,104,1]
	std::cout << "\n";
	std::ofstream fout("../../../media/lab_02/test.txt");	// output to file
	ilist.output(fout);
}