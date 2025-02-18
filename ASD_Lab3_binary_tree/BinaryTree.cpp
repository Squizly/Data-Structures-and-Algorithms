#include <iostream>
#include <climits>
#include <vector>

#include "BinaryTree.h"

BinaryTree::BinaryTree() : root(new Node(INT_MAX)), current_vertex(NULL), parent_vertex(NULL) {}

void BinaryTree::deleteTree(Node* currentNode)
{
	if (!currentNode) {
		
		deleteTree(currentNode->left_child);
		deleteTree(currentNode->right_child);

		delete currentNode;
	}
}

BinaryTree::~BinaryTree()
{
	deleteTree(root);
}

void BinaryTree::add(int value)
{
	Node* insertValue = new Node(value);

	parent_vertex = root;
	current_vertex = root->left_child;

	while (current_vertex != NULL) {

		parent_vertex = current_vertex;

		current_vertex = (value > current_vertex->value) ?
			current_vertex->right_child : current_vertex->left_child;


		// TO DO: CHECK UNIQUE VALUE. MAYBE VALUE EXIST IN THE TREE!!!!!
	}

	//std::cout << "parent_vertex->right_child address : " << &parent_vertex->right_child << std::endl;
	//std::cout << "parent_vertex->left_child address : " << &parent_vertex->left_child << std::endl;
	//std::cout << "current_vertex address : " << &current_vertex << std::endl;

	if (value > parent_vertex->value) {
		parent_vertex->right_child = insertValue;
		std::cout << "Value " << value << " insert in right subtree" << std::endl;
	}
	else {
		parent_vertex->left_child = insertValue;
		std::cout << "Value " << value << " insert in left subtree" << std::endl;
	}


}
