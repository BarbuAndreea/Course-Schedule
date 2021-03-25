#pragma once
#include "BSTNode.h"
#include "Iterator.h"
class SortedSet
{
private:
	BSTNode* root;

	BSTNode* insert_rec(BSTNode* node, TElem e);
	void remove_rec(BSTNode*& node, TElem e);
	bool search_rec(BSTNode* node,  TElem e);
	int size_rec(BSTNode* node);

public:

	SortedSet();
	~SortedSet() {
		makeEmpty(root);
	}
	BSTNode* add(TElem e);
	void remove(TElem e);
	int size();
	bool isEmpty();
	void makeEmpty(BSTNode* node);
	bool search(TElem e);
	friend class Iterator;
	Iterator iterator();
	BSTNode* getRoot();
};

