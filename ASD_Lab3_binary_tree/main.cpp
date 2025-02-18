#include <iostream>
#include <vector>
#include <random>
#include <numeric>

#include "BinaryTree.h"

void printVector(std::vector<int>& array)
{
    std::cout << "[ ";
    for (int value : array)
        std::cout << value << " ";
    std::cout << "] "<< std::endl;
}

int main() {
    
	setlocale(0, "Rus");

	BinaryTree firstTree;
    
    firstTree.add(5);
    firstTree.add(3);
    firstTree.add(7);
    
    // 3-ий метод сгенерировать массив случайных целочисленных значений.
    // Creating a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 30);
    
    // Create and fill array
    std::vector<int> values(10);
    std::generate(values.begin(), values.end(), [&]() { return dist(gen); });
    
    
    
    
	return 0;
}
