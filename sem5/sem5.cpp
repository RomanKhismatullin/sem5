#include <iostream>
#include "Positionable.h"
#include "MockManipulator.h"

//int main() {
//	MockManipulator* mm = new MockManipulator();
//	Positionable* s = new Positionable(1, 0, 1.5, 2.5, 0);
//	std::cout << s->X();
//}

#include "Sequence.h"
#include "Element.h"
#include "ActionMove.h"
#include <assert.h>

int main() {
	auto mn = new MockManipulator();
	auto el = new Element(0, 1);
	mn->AddElement(el);
	auto sq = new Sequence(mn);
	IAction* a1 = new ActionMove(0, 2.0);
	sq->Add(a1);
	int j = sq->Next();
	assert(!j);
	std::cout << "GOOD!";
	//ASSERT_FALSE(j);
	//ASSERT_EQ(el->Alpha(), 2.0);
}