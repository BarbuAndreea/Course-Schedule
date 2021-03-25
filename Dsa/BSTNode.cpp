#include "BSTNode.h"

BSTNode::BSTNode()
{
	left = nullptr;
	right = nullptr;
}

BSTNode::BSTNode(TElem e)
{
	left = nullptr;
	right = nullptr;
	info = e;
}

BSTNode::~BSTNode()
{
}

BSTNode*& BSTNode::get_left()
{
	return left;
}

BSTNode*& BSTNode::get_right()
{
	return right;
}

TElem& BSTNode::get_info()
{
	return info;
}

void BSTNode::set_left(BSTNode* new_left)
{
	left = new_left;
}

void BSTNode::set_right(BSTNode* new_right)
{
	right = new_right;
}

void BSTNode::set_info(TElem e)
{
	info = e;
}
