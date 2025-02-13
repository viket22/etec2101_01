#pragma once
/// <summary>
/// array_list.h : implements a dynamic array that can be automatically resized as the elements inside are added or removed.
/// </summary>
namespace ssuds
{
	template <class T>
	/// <summary>
	/// templated dynamic array class that provides similar functionality to std::vector.
	/// </summary>
	class ArrayList
	{
	private:
		T* my_array;
		unsigned int my_array_size;
		unsigned int my_array_capacity;

	public:
		/// <summary>
		/// default constructor, initializes default values for my_array.
		/// </summary>
		ArrayList()
		{
			my_array_capacity = 5;
			my_array = new T[my_array_capacity];
			my_array_size = 0;
		}

		/// <summary>
		/// ArrayList constructor, passed reserved_space by user to preset the array capacity.
		/// </summary>
		/// <param name="reserved_space"></param>
		ArrayList(unsigned int reserved_space) {
			my_array_capacity = reserved_space;
			my_array = new T[my_array_capacity];
			my_array_size = 0;
		}

		/// <summary>
		/// ArrayList destructor.
		/// </summary>
		~ArrayList()
		{
			delete[] my_array;
		}

		/// <summary>
		/// returns the size of my_array as an integer.
		/// </summary>
		/// <returns>my_array_size</returns>
		int size() {
			return my_array_size;
		}

		/// <summary>
		/// returns the size of my_array_capacity as an integer.
		/// </summary>
		/// <returns>my_array_capacity</returns>
		int capacity() {
			return my_array_capacity;
		}

		/// <summary>
		/// allows the user to set the capacity of the ArrayList
		/// </summary>
		/// <param name="new_capacity"></param>
		void reserve(unsigned int new_capacity) {
			my_array_capacity = new_capacity;
		}

		/// <summary>
		/// takes a value from the user and appends it to the end of the array.
		/// </summary>
		/// <param name="new_value"></param>
		void append(const T& new_value)
		{

			// check if the current array size is the same as capacity size (need to double capacity), if so make a new
			// array with updated capacity and copy all values over.
			if (my_array_size == my_array_capacity) {
				// double capacity and increase array size by 1 for the prepend.
				my_array_capacity *= 2;

				// create a new temporary array.
				T* new_array = new T[my_array_capacity];

				for (int i = 0; i < my_array_size; i++) {
					new_array[i] = my_array[i];
				}

				delete[] my_array;
				my_array = new_array;
			}

			my_array[my_array_size] = new_value;
			my_array_size++;
		}

		/// <summary>
		/// takes a value from the user and prepends it to the beginning of the array.
		/// </summary>
		/// <param name="new_value"></param>
		void prepend(const T& new_value)
		{
			// check if the current array size is the same as capacity size (need to double capacity), if so make a new
			// array with updated capacity and copy all values over.
			if (my_array_size == my_array_capacity) {
				// double capacity and increase array size by 1 for the prepend.
				my_array_capacity *= 2;

				// create a new temporary array.
				T* new_array = new T[my_array_capacity];

				for (int i = 0; i < my_array_size; i++) {
					new_array[i + 1] = my_array[i];
				}

				delete[] my_array;
				my_array = new_array;
			}
			else {
				// loop through and shift values in array right by 1 if no resizing is needed.
				for (int i = my_array_size; i > 0; i--) {
					my_array[i] = my_array[i - 1];
				}
			}
			my_array[0] = new_value;
			// increment array size since a value was added.
			my_array_size++;
		}

		/// <summary>
		/// allows the user to insert a value at any id in the array, and pushes the values down to make room for the new value.
		/// </summary>
		/// <param name="value"></param>
		/// <param name="id"></param>
		void insert(const T& value, unsigned int id) {
			if (id < 0 || id > my_array_size) {
				throw std::out_of_range("Out of range!");
			}
			// check if the current array size is the same as capacity size (need to double capacity), if so make a new
			// array with updated capacity and copy all values over.
			if (my_array_size == my_array_capacity) {
				// double capacity and increase array size by 1 for the prepend.
				my_array_capacity *= 2;

				// create a new temporary array.
				T* new_array = new T[my_array_capacity];

				for (int i = 0; i < my_array_size; i++) {
					new_array[i] = my_array[i];
				}

				delete[] my_array;
				my_array = new_array;
			}
			// if neither, go ahead and insert the value and shift over all other values to make room.
			if (id >= 0 || id <= my_array_size) {
				// loop through and shift values in array after the given index
				for (int i = my_array_size; i > id; i--) {
					my_array[i] = my_array[i - 1];
				}
			}
			my_array[id] = value;
			// increment array size since a value was added.
			my_array_size++;
		}

		/// <summary>
		/// allows the user to specify a certain id to remove in the array.
		/// </summary>
		/// <param name="id"></param>
		void remove(unsigned int id)
		{
			// throw an out of range error if id is larger than the array size.
			if (id >= my_array_size) {
				throw std::out_of_range("Out of range!");
			}

			// shift values in array to the left to remove the value at the id given.
			for (int i = id; i < my_array_size - 1; i++) {
				my_array[i] = my_array[i + 1];
			}
			
			// decrement array size since a value was rmeoved.
			my_array_size--;

			// if the size of the array is less than half of the capacity, half the capacity as to not waste resources.
			if (my_array_size < my_array_capacity / 2) {
				// half capacity.
				my_array_capacity /= 2;

				// create a new temporary array with the decreased capacity.
				T* new_array = new T[my_array_capacity];

				// copy over everything from the old array to the new one.
				for (int i = 0; i < my_array_size; i++) {
					new_array[i] = my_array[i];
				}

				delete[] my_array;
				my_array = new_array;
			}
		}

		/// <summary>
		/// allows the user to specify a specific value, and removes all occurrences of that value in the array.
		/// </summary>
		/// <param name="value"></param>
		/// <returns>removed_count</returns>
		int remove_all(const T& value) {
			int removed_count = 0;
			int i = 0;
			// while loop used, since when an item is removed within a for loop, the i index increments unconditionalliy,
			// causing some values to be skipped which we may want to remove.
			while (i < my_array_size) {
				if (my_array[i] == value) {
					remove(i);
					removed_count++;
				}
				else {
					// we only want to increment i if no values have been removed, since we dont want to skip any.
					i++;
				}
			}
			return removed_count;
		}

		/// <summary>
		/// returns the value at any given index.
		/// </summary>
		/// <param name="index"></param>
		/// <returns>my_array[index]</returns>
		T at(unsigned int index) const
		{
			// check if index is invalid, if so throw out of range error
			if (index >= my_array_size || index < 0) {
				throw std::out_of_range("Out of range!");
			}
			else {
				return my_array[index];
			}
		}

		/// <summary>
		/// finds what value is at any given index, can be passed a certain index to start from, default value is 0.
		/// </summary>
		/// <param name="search_value"></param>
		/// <param name="start_index"></param>
		/// <returns>i</returns>
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


		/// <summary>
		/// takes a reference to an ostream object and produce an output.
		/// </summary>
		/// <param name="os"></param>
		void output(std::ostream& os)
		{
			os << "[";
			// only print the first value without spaces or commas if theres only one thing in the array.
			if (my_array_size == 1) {
				os << my_array[0];
			}
			// if more than one item print as normal. skipped if nothing in array and only prints square brackets.
			else if (my_array_size > 1) {
				for (int i = 0; i < my_array_size - 1; i++) {
					os << my_array[i] << ", ";
				}
				os << my_array[my_array_size - 1];
			}
			os << "]";
		}
	};
}