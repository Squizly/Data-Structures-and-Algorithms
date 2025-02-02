#include <iostream>
#include <vector>
#include <random>

#include "Sort.h"

int main()
{
	const int size_array = 1000000;

	// Creating a random number generator
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(1, size_array-1);

	setlocale(0, "Rus");
	
	// create arrays
	std::vector<int> ascending_array(size_array);
	std::vector<int> descending_array(size_array);
	std::vector<int> random_array(size_array);

	// fill arrays
	for (int i = 0; i < size_array; i++) {
		ascending_array[i] = i;
		descending_array[i] = (size_array - 1) - i;
		random_array[i] = dist(gen);
	}

	int* pointer_ascending = &ascending_array[size_array-1];

	std::cout << *pointer_ascending << std::endl;


	return 0;
}