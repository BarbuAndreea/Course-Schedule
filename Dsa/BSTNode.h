#pragma once
#include "TElem.h"
class BSTNode
{
private:
	BSTNode* left;
	BSTNode* right;
	TElem info;
public:
	BSTNode();
	BSTNode(TElem e);
	~BSTNode();
	BSTNode*& get_left();
	BSTNode*& get_right();
	TElem& get_info();
	void set_left(BSTNode* new_left);
	void set_right(BSTNode* new_right);
	void set_info(TElem);
};

