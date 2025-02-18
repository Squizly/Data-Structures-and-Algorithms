#include <iostream>
#include <vector>

#include "BinaryTree.h"

int main() {
	setlocale(0, "Rus");

	std::vector<int> keys = { 5, 7, 2, 1, 9, 3, 4, 10};

	BinaryTree firstTree;

	firstTree.add(5);
	firstTree.add(3);
	firstTree.add(5);

	return 0;
}