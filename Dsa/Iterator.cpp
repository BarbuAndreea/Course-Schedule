#include "Iterator.h"


Iterator::Iterator(const SortedSet& bst)
{
	BSTNode* curr = bst.root;
	while (curr != nullptr)
	{
		stack.push(curr);
		curr = curr->get_left();
	}
	if (stack.empty() == false)
		current = stack.top();
	else
		current = nullptr;
};

TElem Iterator::get_current()
{
	if (current == nullptr)
		throw std::exception("Does not exist");
	else
		return current->get_info();
}

bool Iterator::valid()
{
	if (current == nullptr)
		return false;
	else
		return true;
}

void Iterator::next()
{
	if (current == nullptr)
		throw std::exception("Is empty.");

	BSTNode* node = stack.top();
	stack.pop();
	if (node->get_right() != nullptr) {
		node = node->get_right();

		while (node != nullptr) {
			stack.push(node);
			node = node->get_left();
		}
	};
	if (stack.empty() == false)
		current = stack.top();
	else
		current = nullptr;
}
