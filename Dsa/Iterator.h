#pragma once
#include <stack>
#include "SortedSet.h"

class SortedSet;

class Iterator
{
private:
	BSTNode* current;
	stack<BSTNode*> stack;
public:
	~Iterator() {

	}
	Iterator(const SortedSet& bst);
	TElem get_current();
	bool valid();
	void next();
};

