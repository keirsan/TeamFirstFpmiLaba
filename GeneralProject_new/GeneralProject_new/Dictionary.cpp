/*
#include "Dictionary.h"
#include <iostream>
#include <string>
using namespace std;

Dictionary::Dictionary()
{ 
	root = 0;
	rootT = 0;
}

Dictionary::~Dictionary()
{
	if (root)
	{
		if (root->right)
			delTree(root->left);
		if (root->left)
			delTree(root->right);
		delete root;
	}
}

void Dictionary::add(int key, string value)
{
	Node *cur = root;
	if(!root)
	{
		root = new Node;
		root->key = key;
		root->value = value;
		root->left = root->right = 0;
	}

	else 
	{
		while((cur->right != 0 && cur->left != 0) || cur->value != value)
		{
			if(value > cur->value)
			{
				if(cur->right == 0)
				{
					Node *temp = cur;
					cur->right = new Node;
					cur = cur->right;
					cur->parent = temp;
					cur->key = key;
					cur->value = value;
					cur->right = cur->left = 0;
				}
				else cur = cur->right;
			}
			if(value < cur->value)
			{
				if(cur->left == 0)
				{
					Node *temp = cur;
					cur->left = new Node;
					cur = cur->left;
					cur->parent = temp;
					cur->key = key;
					cur->value = value;
					cur->left = cur->right = 0;
				}
				else cur = cur->left;
			}
		}
	}
}

void Dictionary::addTerm(string str, int value)
{
	double key = atof(str.c_str());
	NodeT *cur = rootT;
	if(!rootT)
	{
		rootT = new NodeT;
		rootT->keyT = key;
		rootT->valueT = value;
		last = value;
		rootT->left = rootT->right = 0;
	}

	else 
	{
		while((cur->right != 0 && cur->left != 0) || sin(cur->keyT) != sin(key))
		{
			if(sin(key) > sin(cur->keyT))
			{
				if(cur->right == 0)
				{
					NodeT *temp = cur;
					cur->right = new NodeT;
					cur = cur->right;
					cur->parent = temp;
					cur->keyT = key;
					cur->valueT = value;
					last = value;
					cur->right = cur->left = 0;
				}
				else cur = cur->right;
			}
			if(sin(key) < sin(cur->keyT))
			{
				if(cur->left == 0)
				{
					NodeT *temp = cur;
					cur->left = new NodeT;
					cur = cur->left;
					cur->parent = temp;
					cur->keyT = key;
					cur->valueT = value;
					last = value;
					cur->left = cur->right = 0;
				}
				else cur = cur->left;
			}
		}
	}
}

int Dictionary::search(string value, bool& isOK)
{
	Node *cur = root;
	while(cur)
	{
		if(value < cur->value)
		{
			cur = cur->left;
		}
		else if(value > cur->value)
		{
			cur = cur->right;
		}
		else if(cur->value == value)
			return cur->key;
	}
    isOK = false;
    return 0;
}

int Dictionary::searchTerm(string str, bool& isOK)
{
	double key = atof(str.c_str());
	NodeT *curr = rootT;
	while(curr)
	{
		if(sin(key) > sin(curr->keyT))
		{
			curr = curr->right;
		}
		else if(sin(key) < sin(curr->keyT))
		{
			curr = curr->left;
		}
		else if(sin(curr->keyT) == sin(key))
			return curr->valueT;
	}
	isOK = false;
    return 0;
}

void Dictionary::show(Node *root, int level)
{
	
	Node *cur = root;
	if(root)
	{
		show(root->right, level + 1);
		for(int i = 0; i < level; i++)
			cout << "  ";
		cout << root->key <<" "<< root->value << endl;
		show(root->left, level + 1);
	}
}

void Dictionary::delTree(Node *root)
{
	if (root)
	{
		if (root->right)
			delTree(root->left);
		if (root->left)
			delTree(root->right);
		delete root;
	}
}

Polynom Dictionary::getlast()
{
	return last;
}*/