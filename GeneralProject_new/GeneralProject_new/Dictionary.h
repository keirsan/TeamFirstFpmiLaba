/*#pragma once
#include <string>
#include "Polynom.h"

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

	struct NodeT
	{
		double keyT;
		Polynom valueT;
		NodeT *left;
		NodeT *right;
		NodeT *parent;
	};

private: 
	Node *root;
	NodeT *rootT;
	Polynom last;
public:
	Dictionary();
	~Dictionary();
	Node *getRoot()
	{ return root;}
	NodeT *getRootT()
	{ return rootT;}
	void add(int value, string c);
	void addTerm(string key, Polynom value);
	int search(string value, bool&);
	Polynom searchTerm(string str, bool&);
	void show(Node *root, int level);
	void delTree(Node *root);
	Polynom getlast();
};
*/