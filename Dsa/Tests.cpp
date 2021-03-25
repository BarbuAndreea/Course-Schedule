#include "Tests.h"
#include <assert.h>
#include "SortedSet.h"
#include "Iterator.h"
#include <string>
using namespace std;

void RunTests()
{
	SSTests();
	IteratorTests();
}

void IteratorTests()
{
	SortedSet ss;
	TElem e;
	e.set_name("dsa");
	e.set_hour(8);
	BSTNode* node = new BSTNode();
	node->set_info(e);
	ss.add(e);

	TElem e2;
	e2.set_name("Algebra");
	e2.set_hour(22);
	BSTNode* node2 = new BSTNode();
	node2->set_info(e2);
	ss.add(e2);

	TElem e3;
	e3.set_name("Oop");
	e3.set_hour(7);
	BSTNode* node3 = new BSTNode();
	node3->set_info(e3);
	ss.add(e3);

	Iterator it = ss.iterator();
	assert(it.get_current() == e3);
	it.next();
	assert(it.get_current() == e);
	assert(it.valid() == true);
	it.next();
	assert(it.get_current() == e2);
	it.next();
	assert(it.valid() == false);

}

void SSTests()
{
	SortedSet ss;
	assert(ss.isEmpty() == true);

	TElem e;
	e.set_name("dsa");
	e.set_hour(8);
	BSTNode* node = new BSTNode();
	node->set_info(e);
	assert(ss.add(e)->get_info() == node->get_info());

	assert(ss.isEmpty() == false);

	TElem e2;
	e2.set_name("Algebra");
	e2.set_hour(22);
	BSTNode* node2 = new BSTNode();
	node2->set_info(e2);
	ss.add(e2);
	assert(ss.search(e2) == true);

	TElem e3;
	e3.set_name("Oop");
	e3.set_hour(7);
	BSTNode* node3 = new BSTNode();
	node3->set_info(e3);
	assert(ss.add(e3)->get_left()->get_info() == node3->get_info());

	assert(ss.size() == 3);

	ss.remove(e3);
	assert(ss.size() == 2);
	assert(ss.search(e3) == false);

	ss.makeEmpty(ss.getRoot());
	assert(ss.size() == 0);
}
