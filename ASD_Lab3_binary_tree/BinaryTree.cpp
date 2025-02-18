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
        
        if (current_vertex->value == value){
            std::cerr << "Value " << value << " exist in the Tree." << std::endl;
            delete insertValue;
            return;
        }

		parent_vertex = current_vertex;

		current_vertex = (value > current_vertex->value) ?
			current_vertex->right_child : current_vertex->left_child;
	}
    
	if (value > parent_vertex->value) parent_vertex->right_child = insertValue;

	else parent_vertex->left_child = insertValue;
}

void BinaryTree::fillTree(const std::vector<int> &values)
{
    for (int value : values)
        add(value);
}

Node* BinaryTree::find(int value)
{
    helpSearch(value);
    return current_vertex;
    
//    parent_vertex = root;
//    current_vertex = parent_vertex->left_child;
//    
//    while (current_vertex != NULL && current_vertex->value != value){
//        
//        parent_vertex = current_vertex;
//        
//        current_vertex = (value > current_vertex->value) ?
//            current_vertex->right_child : current_vertex->left_child;
//    }
//    
//    return current_vertex;
}

int BinaryTree::helpSearch(int value)
{
    parent_vertex = root;
    current_vertex = parent_vertex->left_child;
    int currentLevel = 1;

    
    while (current_vertex != NULL && current_vertex->value != value){
        
        parent_vertex = current_vertex;
        
        current_vertex = (value > current_vertex->value) ?
            current_vertex->right_child : current_vertex->left_child;
        
        currentLevel++;
    }
    
    if (current_vertex == NULL) return -1;
    return currentLevel;
}

int BinaryTree::getLevel(int value)
{
    int level = helpSearch(value);
    
    if (level == -1) {
        std::cerr << "Value " << value << " not found in the Tree." << std::endl;
        return -1;
    }
    
    return level;
}


