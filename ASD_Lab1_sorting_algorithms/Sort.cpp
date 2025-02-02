#ifndef TEMPLATE_SORT
#define TEMPLATE_SORT

#include <iostream>
#include <vector>

#include "Sort.h"

template <typename Type>
int Sort<Type>::shell_sort(std::vector<Type*>& array)
{
	int count_comparisons = 0;

	for (int step = array.size() / 2; step > 0; step /= 2) {
		
		for (int i = 0; i < array.size() - step; i++) {

			int j = i;

			while (j >= 0 && *array[j] > *array[j + step]) {

				std::swap(array[j], array[j + step]);

				j -= step;
				count_comparisons++;
			}

			// If only second condition in while failed
			if (j >= 0)
				count_comparisons++;
		}

	}

	return count_comparisons;
}

template <typename Type>
bool Sort<Type>::check_sorting(std::vector<Type*> array)
{

	for (int i = 0; i < array.size()-1; i++) {
		if (*array[i] > *array[i + 1]) {
			std::cerr << "Failed! The array is not sorted!" << std::endl;
			return false;
		}
	}
	return true;

}

#endif