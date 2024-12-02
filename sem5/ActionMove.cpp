#include "ActionMove.h"

ActionMove::ActionMove(int _n, double fi) {
	N = _n;
	Fi = fi;
}

int ActionMove::DoWork(IManipulator* mn) {
	auto s = mn->GetElement(N);
	auto ss = dynamic_cast<Element*>(s);
	if (ss == nullptr)
		return 1;
	return mn->MoveElem(N, Fi);
};