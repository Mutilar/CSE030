#include "BTree.h"
#include <iostream>
using namespace std;

BTree::BTree()
{
	root = NULL;
}
BTree::~BTree()
{
	destroy_tree();
}

void BTree::insert(int key)
{
	if (root == NULL)
	{
		root = new Node();
		root->key_value = key;
	}
	else insert(key, root);
}

Node* BTree::search(int key)
{
	search(key, root);
}

void BTree::destroy_tree()
{
	destroy_tree(root);
}

Node* BTree::BTree_root()
{
	return root;
}

void BTree::destroy_tree(Node* leaf)
{
	if (leaf->left != NULL) destroy_tree(leaf->left);
	if (leaf->right != NULL) destroy_tree(leaf->right);
	delete leaf;
}

void BTree::insert(int key, Node* leaf)
{
	
	if (key <= leaf->key_value)
	{
		if (leaf->left == NULL)
		{
			leaf->left = new Node();
			leaf->left->key_value = key;
		}
		else insert(key, leaf->left);
	}
	else if (key > leaf->key_value)
	{
		if (leaf->right == NULL)	
		{
			leaf->right = new Node();
			leaf->right->key_value = key;
		}
		else insert(key, leaf->right);
	}	
}

Node* BTree::search(int key, Node* leaf)
{
	if (leaf == NULL) return NULL;
	else if (key == leaf->key_value) return leaf;
	else if (key < leaf->key_value) search(key,leaf->left);
	else if (key > leaf->key_value) search(key,leaf->right);
}

