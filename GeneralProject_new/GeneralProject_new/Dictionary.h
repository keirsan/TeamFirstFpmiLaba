#pragma once
#include <string>

using namespace std;

class Dictionary
{
public: 
	struct Node
	{
		int key;
		string value;
		Node *left;
		Node *right;
		Node *parent;
	};

private: 
	Node *root;
public:
	Dictionary();
	~Dictionary();
	Node *getRoot()
	{ return root;}
	void add(int value, string c);
	int search(string value, bool&);
	void show(Node *root, int level);
	void delTree(Node *root);
};
