#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>

#include "BinaryTree.h"

BinaryTree::BinaryTree() : root(new Node(INT_MAX)), current_vertex(NULL), parent_vertex(NULL) {}

void BinaryTree::add_vertex(int value)
{
	// Так как каждая новая вершина это лист, то создаем новый узел
	Node* new_node = new Node(value);

	parent_vertex = root; // Идем с верха дерева (фиксированную вершину пропускаем)
	current_vertex = parent_vertex->left_child; // У фиксированной вершины только левой поддерево
	
	// Ищем место для нового узла
	while (current_vertex != NULL) {

		// Проверяем, что новое значение уникально
		if (current_vertex->value == value) {
			delete new_node;
			return;
		}

		// Тут будет хранится лист к которой добавим новую вершину
		parent_vertex = current_vertex;

		// В правом поддереве содержатся значения > значения корня
		if (value > current_vertex->value)
			current_vertex = current_vertex->right_child;
		// В левом поддереве значения <= значения корня
		else
			current_vertex = current_vertex->left_child;
	}

	// Добавляем новую вершину
	if (value > parent_vertex->value)
		parent_vertex->right_child = new_node;
	else
		parent_vertex->left_child = new_node;

}

void BinaryTree::remove_vertex(int value)
{
	// Проверяем что такое значение есть в дереве
	if (search_vertex(value) == NULL) {
		std::cerr << "The value " << value << " is not in the tree." << std::endl;
		return;
	}
	
	// После метода search_vertex(value)
	// current_vertex указывает на удаляемую вершину
	// parent_vertex на её родителя

	// Дальше будут 4 возможных случая исключаемой вершины

	// 1. Удаляемая вершина - это лист :
	if (current_vertex->left_child == NULL && current_vertex->right_child == NULL) {

		// Если удаляемая вершина в левом поддереве
		if (current_vertex == parent_vertex->left_child)
			parent_vertex->left_child = NULL;
		else // В правом
			parent_vertex->right_child = NULL;
	}

	// 2. У удаляемой вершины есть ТОЛЬКО левое поддерево :
	else if (current_vertex->right_child == NULL) {

		// Исключаемая вершина находится в левом поддереве родителя
		if (current_vertex == parent_vertex->left_child)
			parent_vertex->left_child = current_vertex->left_child;
		else // В правом
			parent_vertex->right_child = current_vertex->left_child;
	}

	// 3. У удаляемой вершины есть ТОЛЬКО правое поддерево :
	else if (current_vertex->left_child == NULL) {

		// Удаляемая вершина находится в левом поддереве родителя
		if (current_vertex == parent_vertex->left_child)
			parent_vertex->left_child = current_vertex->right_child;
		else // В правом
			parent_vertex->right_child = current_vertex->right_child;
	}

	// 4. У удаляемой вершины есть оба поддерева :
	else {
		// Запоминаем current
		Node* found = current_vertex;

		// Идем в левое поддерево удаляемой вершины
		parent_vertex = current_vertex;
		current_vertex = current_vertex->left_child;

		// Ищем максимум в левом поддереве удаляемой вершины
		while (current_vertex->right_child != NULL) {
			parent_vertex = current_vertex;
			current_vertex = current_vertex->right_child;
		}

		// Максимальное значение из левого поддерева помещаем в значение удаляемой вершины
		if (current_vertex == parent_vertex->left_child)
			parent_vertex->left_child = current_vertex->left_child;
		else
			parent_vertex->right_child = current_vertex->left_child;

		found->value = current_vertex->value;
		// Затем удаляем лишнию вершину с тем же значением что сейчас в "удаляемой" вершине
	}
	
	delete current_vertex;
}

void BinaryTree::build_tree(const std::vector<int>& values)
{
	for (int value : values)
		add_vertex(value);
}

void BinaryTree::build_optimal_tree(const std::vector<int>& values)
{
	if (root->left_child != NULL) {
		std::cerr << "The tree has vertex. We need an empty tree." << std::endl;
		return;
	}

	std::vector<int> sortedValues = values;
	std::sort(sortedValues.begin(), sortedValues.end());

	// Удаление дубликатов
	// unique перемешает уникальные значения в начало, а дубликаты в конец (возвращает итератор на первый дубликат)
	sortedValues.erase(std::unique(sortedValues.begin(), sortedValues.end()), sortedValues.end());

	// От фиксированной вершины строим левое поддерево
	parent_vertex = helper_build_optimal_tree(sortedValues, 0, sortedValues.size()-1);
	root->left_child = parent_vertex;
}

Node* BinaryTree::helper_build_optimal_tree(const std::vector<int>& values, int start, int end)
{
	if (start > end)
		return nullptr;

	int middle_element = (start + end) / 2;

	Node* new_node = new Node(values[middle_element]);

	new_node->left_child = helper_build_optimal_tree(values, start, middle_element - 1);
	new_node->right_child = helper_build_optimal_tree(values, middle_element + 1, end);

	return new_node;
}

Node* BinaryTree::search_vertex(int value)
{
	helper_search(value);
	// If value not found in the tree - return NULL
	return current_vertex;
}

int BinaryTree::get_level(int value)
{
	// If value not found in the tree - return -1.
	return helper_search(value);
}

int BinaryTree::helper_search(int value)
{
	parent_vertex = root;
	current_vertex = parent_vertex->left_child;

	int current_level = 1;

	while (current_vertex != NULL && current_vertex->value != value) {

		parent_vertex = current_vertex;
		current_level++;

		if (value > current_vertex->value)
			current_vertex = current_vertex->right_child;
		else
			current_vertex = current_vertex->left_child;
	}

	if (current_vertex == NULL) {
		return -1;
	}

	return current_level;
}

void BinaryTree::print()
{
	std::cout << "Binary tree have values : [ ";
	helper_print(root->left_child);
	std::cout << "]" << std::endl;
}

void BinaryTree::helper_print(Node* node)
{
	if (node == NULL)
		return;
	
	helper_print(node->left_child);
	std::cout << node->value << " ";
	helper_print(node->right_child);
}

std::vector<int> BinaryTree::search_in_range(int start, int end)
{
	std::vector<int> keys;

	if (start > end) {
		std::cerr << "BinaryTree:search_in_range : Error. start > end" << std::endl;
		return keys;
	}

	for (int value = start; value <= end; value++) {

		if (search_vertex(value) != NULL)
			keys.push_back(value);

	}

	return keys;
}

void BinaryTree::calculate_levels(int& max_level, int& average_level)
{
	int total_levels = 0, count = 0;
	max_level = 0;

	// Один проход по дереву для расчета максимального и среднего уровня
	helper_calculate_levels(root->left_child, 1, total_levels, count, max_level);

	// Вычисление среднего уровня
	average_level = (count == 0) ? 0 : double(total_levels) / count;
}

void BinaryTree::helper_calculate_levels(Node* node, int level, int& total_levels, int& count, int& max_level)
{
	if (node == NULL)
		return;

	// Обновляем максимальный уровень
	max_level = std::max(max_level, level);

	// Добавляем уровень текущей вершины к общей сумме
	total_levels += level;
	count++;

	// Рекурсивно вызываем для левого и правого поддеревьев
	helper_calculate_levels(node->left_child, level + 1, total_levels, count, max_level);
	helper_calculate_levels(node->right_child, level + 1, total_levels, count, max_level);
}
