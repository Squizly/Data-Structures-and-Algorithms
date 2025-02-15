#pragma once

struct Node
{
	int key;
	Node* left, * right;

	Node(int value) {
		key = value;
		left = nullptr;
		right = nullptr;
	}

};

class BinaryTree
{
public:

	BinaryTree();
	BinaryTree(int key);


private:

	Node* current_vertex = nullptr;
	Node* parent_vertex = nullptr;
	Node* root = nullptr;

};