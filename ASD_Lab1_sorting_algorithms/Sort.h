#pragma once

#ifndef ARE_TEMPLATE_SORT_DECLARED
#define ARE_TEMPLATE_SORT_DECLARED


template <typename Type>
class Sort
{

public:

	/* == = == = == = == = == = == = == = == == = == = == = == = */
	static int shell_sort(std::vector<Type*>& array);

	/* == = == = == = == = == = == = == = == == = == = == = == = */
	static int heap_sort(std::vector<Type*>& array);
	static void sifting(std::vector<Type*>& array, const int size, int index, int& comparisons);

	/* == = == = == = == = == = == = == = == == = == = == = == = */
	static bool check_sorting(std::vector<Type*> array);

};

#include "Sort.cpp"

#endif // TEMPLATE_SORT_DECLARED