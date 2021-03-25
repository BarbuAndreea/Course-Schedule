#include "SortedSet.h"

SortedSet::SortedSet()
{
	this->root = nullptr;
}

BSTNode* SortedSet::insert_rec(BSTNode* node, TElem e)
{
	if (node == nullptr) {
		node = new BSTNode(e);
	}
	else if (node->get_info() == e)
		throw std::exception("There is already a course at this time.");
	else if (node->get_info() > e)
		node->set_left(insert_rec(node->get_left(), e));
	else
		node->set_right(insert_rec(node->get_right(), e));
	return node;
}

void SortedSet::remove_rec(BSTNode*& node, TElem e)
{
	if (node == nullptr)
		throw std::exception("Does not exist");
	else if (node->get_info() > e)
		remove_rec(node->get_left(), e);
	else if (node->get_info() < e)
		remove_rec(node->get_right(), e);
	else {
		if (node->get_left() == nullptr || node->get_right() == nullptr) {
			BSTNode* tmp;
			if (node->get_left() == nullptr)
				tmp = node->get_right();
			else
				tmp = node->get_left();
			if (tmp == nullptr) {
				delete node;
				node = NULL;
			}
			else {
				*node = *tmp;
				delete tmp;
				tmp = NULL;
			}
		}
		else {
			BSTNode* tmp = node->get_right();
			while (tmp->get_left() != nullptr)
				tmp = tmp->get_left();
			node->set_info(tmp->get_info());
			remove_rec(node->get_right(), tmp->get_info());
		}
	}
}

BSTNode* SortedSet::add(TElem e)
{
	if (this->root == nullptr) {
		this->root = new BSTNode(e);
		return this->root;
	}
	return insert_rec(this->root, e);
}

void SortedSet::remove(TElem e)
{
	this->remove_rec(this->root, e);
}

bool SortedSet::search_rec(BSTNode* node, TElem e)
{
	if (node == nullptr)
		return false;
	else if (node->get_info() == e)
		return true;
	else if (node->get_info() < e)
		return search_rec(node->get_right(), e);
	else
		return search_rec(node->get_left(), e);
}

bool SortedSet::search(TElem e)
{
	return this->search_rec(this->root, e);
}

bool SortedSet::isEmpty()
{
	return this->root == nullptr;
}

void SortedSet::makeEmpty(BSTNode* node) {
	if (node != NULL) {
		makeEmpty(node->get_left());
		makeEmpty(node->get_right());
		this->root = NULL;
		delete node;
	}
}

int SortedSet::size_rec(BSTNode* node)
{
	if (node == NULL)
		return 0;
	else
		return(size_rec(node->get_left()) + 1 + size_rec(node->get_right()));
}

int SortedSet::size()
{
	return size_rec(root);
}

Iterator SortedSet::iterator() {
	return Iterator(*this);
}

BSTNode* SortedSet::getRoot()
{
	return this->root;
}
