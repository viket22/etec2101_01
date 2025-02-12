// array_list.h (no array_list.cpp!!!!)
#pragma once
namespace ssuds
{
	template <class T>
	class ArrayList
	{
	private:
		T* my_array;
		unsigned int my_array_size;
		unsigned int my_array_capacity;

	public:
		ArrayList()
		{
			// Option1: allocate the array to some small size
			my_array_capacity = 5;
			my_array = new T[my_array_capacity];
			my_array_size = 0;

			// Option2: don't allocate the array just yet -- wait until first
			// append/insert/prepend
			//my_array_capacity = 0;
			//my_array_size = 0;
			//my_array = nullptr;
		}

		~ArrayList()
		{
			delete[] my_array;
		}

		int size() {
			return my_array_size;
		}

		int capacity() {
			return my_array_capacity;
		}

		void append(const T& new_value)
		{
			// This *might* make the array bigger....
			// IF the size == capacity, do the "Grow" operation
			//     Make a new temporary array (double our current capacity)
			//     Copy over data from current array to the new one
			//     Free up the old one
			//     Make my_array point to the bigger array
			//     Double capacity value.
			// If size < capacity, just do this



			my_array[my_array_size] = new_value;
			my_array_size++;
		}

		void prepend(T new_value)
		{
			// This is more costly because we need to move all values "up" one index
			// And possibly grow.
		}



		void remove(unsigned int id)
		{
			// When you remove something, you need to take all values after that index and move them
			// "down" one index.  You might need to shrink the array if we drop below half our capacity,
			// a "shrink" operation is needed.
		}

		T at(unsigned int index) const
		{
			// check if index is invalid, if so throw out of range error
			if (index >= my_array_size || index < 0) {
				throw std::out_of_range;
			}
			else {
				return my_array[index];
			}
		}

		int find(const T& search_value, unsigned int start_index = 0)
		{
			// loop through array starting at user given start_index, search for search_value
			// given, return the index if found.
			for (int i = start_index; i < my_array_size; i++) {
				if (my_array[i] == search_value) {
					return i;
				}
			}
			// return -1 if value is not found.
			return -1;
		}


		// ostream is the base class for all output-based streams (cout, ofstream)
		void output(std::ostream& os)
		{
			os << "[";
			// Some kind of loop
			os << "]";
		}
	};
}