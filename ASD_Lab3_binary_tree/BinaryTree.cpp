#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>

#include "BinaryTree.h"

BinaryTree::BinaryTree() : root(new Node(INT_MAX)), current_vertex(NULL), parent_vertex(NULL) {}

void BinaryTree::add_vertex(int value)
{
	// ��� ��� ������ ����� ������� ��� ����, �� ������� ����� ����
	Node* new_node = new Node(value);

	parent_vertex = root; // ���� � ����� ������ (������������� ������� ����������)
	current_vertex = parent_vertex->left_child; // � ������������� ������� ������ ����� ���������
	
	// ���� ����� ��� ������ ����
	while (current_vertex != NULL) {

		// ���������, ��� ����� �������� ���������
		if (current_vertex->value == value) {
			delete new_node;
			return;
		}

		// ��� ����� �������� ���� � ������� ������� ����� �������
		parent_vertex = current_vertex;

		// � ������ ��������� ���������� �������� > �������� �����
		if (value > current_vertex->value)
			current_vertex = current_vertex->right_child;
		// � ����� ��������� �������� <= �������� �����
		else
			current_vertex = current_vertex->left_child;
	}

	// ��������� ����� �������
	if (value > parent_vertex->value)
		parent_vertex->right_child = new_node;
	else
		parent_vertex->left_child = new_node;

}

void BinaryTree::remove_vertex(int value)
{
	// ��������� ��� ����� �������� ���� � ������
	if (search_vertex(value) == NULL) {
		std::cerr << "The value " << value << " is not in the tree." << std::endl;
		return;
	}
	
	// ����� ������ search_vertex(value)
	// current_vertex ��������� �� ��������� �������
	// parent_vertex �� � ��������

	// ������ ����� 4 ��������� ������ ����������� �������

	// 1. ��������� ������� - ��� ���� :
	if (current_vertex->left_child == NULL && current_vertex->right_child == NULL) {

		// ���� ��������� ������� � ����� ���������
		if (current_vertex == parent_vertex->left_child)
			parent_vertex->left_child = NULL;
		else // � ������
			parent_vertex->right_child = NULL;
	}

	// 2. � ��������� ������� ���� ������ ����� ��������� :
	else if (current_vertex->right_child == NULL) {

		// ����������� ������� ��������� � ����� ��������� ��������
		if (current_vertex == parent_vertex->left_child)
			parent_vertex->left_child = current_vertex->left_child;
		else // � ������
			parent_vertex->right_child = current_vertex->left_child;
	}

	// 3. � ��������� ������� ���� ������ ������ ��������� :
	else if (current_vertex->left_child == NULL) {

		// ��������� ������� ��������� � ����� ��������� ��������
		if (current_vertex == parent_vertex->left_child)
			parent_vertex->left_child = current_vertex->right_child;
		else // � ������
			parent_vertex->right_child = current_vertex->right_child;
	}

	// 4. � ��������� ������� ���� ��� ��������� :
	else {
		// ���������� current
		Node* found = current_vertex;

		// ���� � ����� ��������� ��������� �������
		parent_vertex = current_vertex;
		current_vertex = current_vertex->left_child;

		// ���� �������� � ����� ��������� ��������� �������
		while (current_vertex->right_child != NULL) {
			parent_vertex = current_vertex;
			current_vertex = current_vertex->right_child;
		}

		// ������������ �������� �� ������ ��������� �������� � �������� ��������� �������
		if (current_vertex == parent_vertex->left_child)
			parent_vertex->left_child = current_vertex->left_child;
		else
			parent_vertex->right_child = current_vertex->left_child;

		found->value = current_vertex->value;
		// ����� ������� ������ ������� � ��� �� ��������� ��� ������ � "���������" �������
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

	// �������� ����������
	// unique ���������� ���������� �������� � ������, � ��������� � ����� (���������� �������� �� ������ ��������)
	sortedValues.erase(std::unique(sortedValues.begin(), sortedValues.end()), sortedValues.end());

	// �� ������������� ������� ������ ����� ���������
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

	// ���� ������ �� ������ ��� ������� ������������� � �������� ������
	helper_calculate_levels(root->left_child, 1, total_levels, count, max_level);

	// ���������� �������� ������
	average_level = (count == 0) ? 0 : double(total_levels) / count;
}

void BinaryTree::helper_calculate_levels(Node* node, int level, int& total_levels, int& count, int& max_level)
{
	if (node == NULL)
		return;

	// ��������� ������������ �������
	max_level = std::max(max_level, level);

	// ��������� ������� ������� ������� � ����� �����
	total_levels += level;
	count++;

	// ���������� �������� ��� ������ � ������� �����������
	helper_calculate_levels(node->left_child, level + 1, total_levels, count, max_level);
	helper_calculate_levels(node->right_child, level + 1, total_levels, count, max_level);
}
