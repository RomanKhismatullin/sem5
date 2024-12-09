#include <iostream>
#include "Positionable.h"
#include "MockManipulator.h"
#include "Manipulator.h"
#include "Solver.h"


int main() {
	std::cout << "started";
	//MockManipulator* mm = new MockManipulator();
	//Positionable* s = new Positionable(1, 0, 1.5, 2.5, 0);
	//std::cout << s->X();
	//testSeq();
	auto mn = new Manipulator();
	auto el1 = new Element(0, 0, 0, 0, Pi/2, 1);
	auto el2 = new Element(0, 1, 0, 0, Pi/2, 1);
	auto el3 = new Element(1, 2, 0, 0, Pi/2, 1);
	mn->AddElement(el1);
	mn->AddElement(el2);
	mn->AddElement(el3);
	mn->DRW();
	std::cout << mn->MoveElem(1, 0);
	std::cout << "l";

}

#include "Sequence.h"
#include "ActionMove.h"
#include <cassert>
/*void testSeq() {
	auto mn = new MockManipulator();
	auto el = new Element(0, 1);
	mn->AddElement(el);
	auto sq = new Sequence(mn);
	bool disp = false;

	ActionMove* a1 = new ActionMove(0, 2.0);
	ActionMove* a2 = new ActionMove(0, 2.0);
	sq->Add(a1);
	sq->Add(a2);
	int j = sq->Next();
	assert(!j, "#1");
	assert(el->Alpha() == 2.0, "#2");
	j = sq->Next();
	assert(!j, "#3");
	assert(el->Alpha() == 4.0, "#4");

	//j = sq->Next();//no more elements
	//assert(j);
	//assert(el->Alpha() == 4.0);
}

*/

/*#include "Sequence.h"
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
}*/