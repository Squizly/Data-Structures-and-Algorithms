#include <iostream>
#include <vector>
#include <numeric>
#include <random>

#include "Sort.h"


int main()
{
	setlocale(0, "Rus");

	const int SIZE_ARRAY = 1000;

	// Creating a random number generator
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(1, SIZE_ARRAY - 1);
	
	// create arrays
	std::vector<int> ascending_array(SIZE_ARRAY);
	std::vector<int> descending_array(SIZE_ARRAY);
	std::vector<int> random_array(SIZE_ARRAY);

	// fill arrays
	std::iota(ascending_array.begin(), ascending_array.end(), 0);
	std::iota(descending_array.rbegin(), descending_array.rend(), 0);
	std::generate(random_array.begin(), random_array.end(), [&]() { return dist(gen); });

	// Create arrays of pointer
	std::vector<int*> pointer_ascending(SIZE_ARRAY);
	std::vector<int*> pointer_descending(SIZE_ARRAY);
	std::vector<int*> pointer_random(SIZE_ARRAY);

	// Fill arrays of pointer
	for (int i = 0; i < SIZE_ARRAY; i++) {
		pointer_ascending[i] = &ascending_array[i];
		pointer_descending[i] = &descending_array[i];
		pointer_random[i] = &random_array[i];
	}

	int number_comparisons = 0;

	std::cout << "\t\t\t Shell Sort\n" << std::endl;

	number_comparisons = Sort<int>::shell_sort(pointer_ascending);
	std::cout << "Check sort : " << Sort<int>::check_sorting(pointer_ascending) << "\n";
	std::cout << "Number of comparisons : " << number_comparisons << std::endl;

	number_comparisons = Sort<int>::shell_sort(pointer_descending);
	std::cout << "\nCheck sort : " << Sort<int>::check_sorting(pointer_descending) << "\n";
	std::cout << "Number of comparisons : " << number_comparisons << std::endl;

	number_comparisons = Sort<int>::shell_sort(pointer_random);
	std::cout << "\nCheck sort : " << Sort<int>::check_sorting(pointer_random) << "\n";
	std::cout << "Number of comparisons : " << number_comparisons << std::endl;
	
	std::cout << "\t\t\t Heap Sort\n" << std::endl;

	//TO DO:: heap sort


	return 0;
}