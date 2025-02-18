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
	~BinaryTree();

	void add(int value);
    
    void fillTree(const std::vector<int>& values);
    Node* find(int value);
    int getLevel(int value);
    
private:

	void deleteTree(Node* currentNode);
    int helpSearch(int value);

};

#endif // BINARYTREE_H
