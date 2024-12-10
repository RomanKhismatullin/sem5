#include <iostream>
#include "Positionable.h"
#include "MockManipulator.h"
#include "Manipulator.h"
#include "Solver.h"
#include "GraphSolver.h"

using std::cout;

//void TST() {
//	std::vector<TreeObj*> tree;
//	tree.push_back(new TreeObj(0, 0));  // Узел 0
//	tree.push_back(new TreeObj(0, 1));  // Узел 1
//	tree.push_back(new TreeObj(1, 2));  // Узел 2
//	tree.push_back(new TreeObj(2, 3));  // Узел 3
//	tree.push_back(new TreeObj(1, 4));  // Узел 4
//	tree.push_back(new TreeObj(4, 5));  // Узел 5
//	tree.push_back(new TreeObj(4, 6));  // Узел 6
//
//	std::vector<TreeObj*> branch;
//
//	// Запускаем для узла 4 (согласно описанию задачи, это начальный узел)
//	cout << GSolver::BuildPredecessorBranch(tree, 4, branch) << " vs " << 3;
//
//	// Проверяем, что в векторе branch будут только узлы 4, 5, и 6
//	cout << branch[0]->N() << " vs " << 4;
//	cout << branch[1]->N() << " vs " << 5;
//	cout << branch[2]->N() << " vs " << 6;
//}

int main() {
	std::cout << "started";
	auto mn = new Manipulator();      
	mn->AddElement(new Element(0, 0, 0, 0, 0, 1));
	mn->AddElement(new Element(0, 1, 1, 0, Pi/2, 1)); // <_	--	
	mn->AddElement(new Element(1, 2, 1, 0, Pi/2, 1)); // _> |
	mn->AddElement(new Element(2, 3, 1, 0, Pi/4, 0.5*std::sqrt(2)));
	mn->DRW();
	std::cout << mn->GetElement(3)->drw << " IS: (0, 1)\n";
	std::cout << mn->GetElement(3)->drw2() << " IS: (-4, -3)\n";

	//std::cout << mn->MoveElem(1, 0) << "\n";
	//std::cout << mn->MoveElem(0, Pi) << "\n";
	//std::cout << mn->GetElement(3)->drw2() << " IS: (4, 3)\n";
	mn->DRW();
	for (int i = 0; i < 4; i++) {
		auto e = mn->GetElement(i);
		cout << e->drw << e->drw2() << e->NPrev() << "-" << e->N() <<"\n";
	}
	//mn->GetElement(3)->TweekAlpha(-Pi);
	std::cout << mn->MoveElem(3, Pi - 1e-4) << "-" << mn->collision << "IS EL: " << mn->Elem_collision << " c" << mn->Const_collision << " m" << mn->Moved_collision << "\n";
	mn->DRW();
	cout << "---------\n";
	for (int i = 0; i < 4; i++) {
		auto e = mn->GetElement(i);
		cout << e->drw << e->drw2() << e->NPrev() << "-" << e->N() << "\n";
	}
	mn->GetElement(3)->TweekAlpha(-Pi/2);
	mn->DRW();
	cout << "---------\n";
	for (int i = 0; i < 4; i++) {
		auto e = mn->GetElement(i);
		cout << e->drw << e->drw2() << e->NPrev() << "-" << e->N() << "\n";
	}

	//cout << solver::CheckSegmentIntersection(new Point(0, 0), new Point(1, 0), new Point(0, 1), new Point(2, -1));
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