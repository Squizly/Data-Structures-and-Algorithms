#ifndef BINARYTREE_H
#define BINARYTREE_H

struct Node
{
	int value;
	Node* left_child, *right_child;

	Node(int val) : value(val), left_child(NULL), right_child(NULL) {}
};

class BinaryTree
{

	Node* current_vertex = NULL;
	Node* parent_vertex = NULL;
	Node* root = NULL;

public:

	BinaryTree();

	void add_vertex(int value);
	void remove_vertex(int value);
	void build_tree(const std::vector<int>& values);
	void build_optimal_tree(const std::vector<int>& values);
	void calculate_levels(int& max_level, int& average_level); //
	void print();

	Node* search_vertex(int value);
	int get_level(int value);

	std::vector<int> search_in_range(int start, int end);

private:
	Node* helper_build_optimal_tree(const std::vector<int>& values, int start, int end);
	int helper_search(int value);
	void helper_print(Node* node);
	void helper_calculate_levels(Node* node, int level, int& total_levels, int& count, int& max_level);
};

#endif // BINARYTREE_H
