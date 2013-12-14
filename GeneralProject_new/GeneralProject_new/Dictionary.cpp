#include "Dictionary.h"
#include <iostream>
#include <string>
using namespace std;

Dictionary::Dictionary()
{ 
	root = 0;
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
		while((cur->right != 0 && cur->left != 0) || cur->key != key)
		{
			if(key > cur->key)
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
			if(key < cur->key)
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

int Dictionary::search(string value)
{
	int flag = 0;
	Node *cur = root;
	while(cur)
	{
		if(value < cur->value)
		{
			cur = cur->right;
		}
		else if(value > cur->value)
		{
			cur = cur->left;
		}
		else if(cur->value == value)
		{
			return cur->key;
			flag = 1;
			break;
		}
	}
	if(flag == 0) cout << "no element" << endl;
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