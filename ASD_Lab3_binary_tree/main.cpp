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

    std::cout << "\n # === === === === === === === === === === === === === === #\n" << std::endl;

    /* === === === === === === === === === === === === === === === === === === === */

    std::cout << "Defaul constructor and add vertex : \n" << std::endl;
    
    BinaryTree firstTree; // Конструктор с фиксированной вершиной.
    firstTree.add_vertex(5); // Добавление вершины с заданным ключом
    firstTree.print(); // Вывод ключей

    std::cout << "\n # === === === === === === === === === === === === === === #\n" << std::endl;

    /* === === === === === === === === === === === === === === === === === === === */

    
    std::cout << "Build Tree (values) and search vertex (value), get_level, remove_vertex : \n" << std::endl;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 100);

    std::vector<int> values(20);
    std::generate(values.begin(), values.end(), [&]() { return dist(gen); });

    BinaryTree secondTree;
    secondTree.build_tree(values);
    secondTree.print();

    std::cout << "\nFind vertex by value : " << secondTree.search_vertex(values[10])->value << std::endl;
    std::cout << "This vertex have level : " << secondTree.get_level(values[10]) << std::endl;
    
    secondTree.remove_vertex(values[10]);

    if (secondTree.search_vertex(values[10]) == NULL)
        std::cout << "\nThis vertex is removed. " << std::endl;
    else
        std::cout << "This vertex is not removed! " << std::endl;

    int max_level_secondTree = 0, average_level_secondTree = 0;
    secondTree.calculate_levels(max_level_secondTree, average_level_secondTree);

    std::cout << "\n # === === === === === === === === === === === === === === #\n" << std::endl;

    /* === === === === === === === === === === === === === === === === === === === */

    std::cout << "Build Optimal Tree (values), search_in_range : \n" << std::endl;

    BinaryTree thirdTree;
    thirdTree.build_optimal_tree(values);
    thirdTree.print();

    std::cout << "\nFind vertex by value : " << thirdTree.search_vertex(values[10])->value << std::endl;
    std::cout << "This vertex have level : " << thirdTree.get_level(values[10]) << std::endl;

    std::cout << "\nGet key in range [ " << 50 << ", " << 100 << " ] : ";
    std::vector<int> newValues = thirdTree.search_in_range(50, 100);

    std::cout << "[ ";
    for (int value : newValues)
        std::cout << value << " ";
    std::cout << "]" << std::endl;

    int max_level_thirdTree = 0, average_level_thirdTree = 0;
    thirdTree.calculate_levels(max_level_thirdTree, average_level_thirdTree);

    std::cout << "\n # === === === === === === === === === === === === === === # \n" << std::endl;

    /* === === === === === === === === === === === === === === === === === === === */

    std::cout << "Calculation of the maximum and average values of the tree node levels : " << std::endl;

    std::cout << "\nSecond Tree (build with array unique values) : " << std::endl;
    std::cout << "Max level : " << max_level_secondTree << std::endl;
    std::cout << "Average level : " << average_level_secondTree << std::endl;

    std::cout << "\nThird Tree (build optimal) : " << std::endl;
    std::cout << "Max level : " << max_level_thirdTree << std::endl;
    std::cout << "Average level : " << average_level_thirdTree << std::endl;



	return 0;
}
