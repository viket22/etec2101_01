#include <iostream>
#include <fstream>
#include <string>
#include <array_list.h>

/// <summary>
/// lab02_main.cpp : main function, to test the ArrayList class
/// </summary>
/// <param name="argc"></param>
/// <param name="argv"></param>
/// <returns></returns>
int main(int argc, char** argv)
{
	// to test an array of type int
	std::cout << "===== Append & Prepend Test =====\n\n";
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
	std::cout << "All occurrences of value '102' (indexes): ";
	
	// while loop used to find all occurrences of a given value, like a find_all function
	bool found = false;
	int starting_index = 0;
	while (true) {
		int found_index = ilist.find(102, starting_index);

		if (found_index == -1) {
			break;
		}

		std::cout << found_index << " ";
		found = true;
		starting_index = found_index + 1;
	}

	std::cout << "\n\n===== Insert Test =====\n\n";

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
	
	// ALTERNATIVE: to test an array of type float

	/*
	std::cout << "===== Append & Prepend Test =====\n\n";
	// create new ArrayList object called ilist
	ssuds::ArrayList<float> ilist;
	ilist.append(100.1);
	ilist.append(101.2);
	ilist.append(102.3);
	ilist.append(103.4);
	ilist.append(104.5);
	ilist.prepend(100.5);
	ilist.prepend(101.4);
	ilist.prepend(102.3);
	ilist.prepend(103.2);
	ilist.prepend(104.1);

	for (int i = 0; i < ilist.size(); i++)
		std::cout << "ilist[" << i << "] = " << ilist.at(i) << "\n";		// Output: [104.5,103.4,102.3,101.2,100.1,100.1,101.2,102.3,103.4,104.5]

	std::cout << "\n===== Remove & Remove All Test =====\n\n";

	ilist.remove(0); // will remove value at index 0 which is 104.5.

	ilist.remove_all(100.1); // will remove all occurences of value 100.1.

	for (int i = 0; i < ilist.size(); i++)
		std::cout << "ilist[" << i << "] = " << ilist.at(i) << "\n";	// Output: [103.4,102.3,101.2,101.2,102.3,103.4,104.5]

	std::cout << "\n===== Find Test =====\n\n";

	int test1 = ilist.find(101.2); // should return 2.

	int test2 = ilist.find(102.3, 3); // should return 4.

	std::cout << "'Find' test 1: " << test1 << "\n'Find' test 2: " << test2 << "\n";	// Output: 'Find' test 1: 2
																						//		   'Find' test 2: 4
	std::cout << "All occurrences of value '102.3' (indexes): ";

	// while loop used to find all occurrences of a given value, like a find_all function
	bool found = false;
	int starting_index = 0;
	while (true) {
		int found_index = ilist.find(102.3, starting_index);

		if (found_index == -1) {
			break;
		}

		std::cout << found_index << " ";
		found = true;
		starting_index = found_index + 1;
	}

	std::cout << "\n\n===== Insert Test =====\n\n";

	// these will insert a '1.1' between every number
	ilist.insert(1.1, 0);
	ilist.insert(1.1, 2);
	ilist.insert(1.1, 4);
	ilist.insert(1.1, 6);
	ilist.insert(1.1, 8);
	ilist.insert(1.1, 10);
	ilist.insert(1.1, 12);
	ilist.insert(1.1, 14);

	for (int i = 0; i < ilist.size(); i++)
		std::cout << "ilist[" << i << "] = " << ilist.at(i) << "\n";	// Output: [1.1,103.4,1.1,102.3,1.1,101.2,1.1,101.2,1.1,102.3,1.1,103.4,1.1,104.5,1.1]

	std::cout << "\n===== Size, Capacity Test & Reserve Test =====\n\n";

	std::cout << "Array Size: " << ilist.size() << "\nArray Capacity (before reserve): " << ilist.capacity() << "\n";

	ilist.reserve(50);

	std::cout << "Array Capacity (after reserve): " << ilist.capacity() << "\n";

	std::cout << "\n===== ostream Test =====\n\n";

	ilist.output(std::cout);											// Output: [1.1,103.4,1.1,102.3,1.1,101.2,1.1,101.2,1.1,102.3,1.1,103.4,1.1,104.5,1.1]
	std::cout << "\n";
	std::ofstream fout("../../../media/lab_02/test.txt");	// output to file
	ilist.output(fout);
	*/
}