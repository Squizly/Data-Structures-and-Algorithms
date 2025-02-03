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

template<typename Type>
void Sort<Type>::sifting(std::vector<Type*>& array, const int size, int index_parent, int& comparisons)
{
    // get first child for this parent
    int index_child = 2 * index_parent + 1;

    // 
    while (index_parent < size) {

        if (index_child < size) {

            // second child exist.
            if ((index_child + 1) < size) {
                comparisons++; // if second child exist => comparison

                // get max child for this parent.
                if (*array[index_child + 1] > *array[index_child]) 
                    index_child = index_child + 1;
                }

            comparisons++; // comparison child and parent

            // maybe child > parent => swap.
            if (*array[index_parent] < *array[index_child]) {
                std::swap(array[index_parent], array[index_child]);
                index_parent = index_child;
                index_child = 2 * index_parent + 1;
            }

            //  if all children for this parent is small.
            else 
                index_parent += size;
        }
        else
            index_parent += size;
    }

}

template <typename Type>
int Sort<Type>::heap_sort(std::vector<Type*>& array) {

    const int size = array.size();
    int number_comparisons = 0;


    // we don't take last elements , because the don't have children.
    for (int i = size / 2 - 1; i >= 0; i--) {
        sifting(array, size, i, number_comparisons);
    }

    for (int j = size - 1; j > 0; --j) {
        std::swap(array[0], array[j]);

        // j -> current_size (-1 because last element is max)
        sifting(array, j, 0, number_comparisons);
    }
    return number_comparisons;
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

#endif // TEMPLATE_SORT