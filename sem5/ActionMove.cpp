#include "ActionMove.h"

ActionMove::ActionMove(int _n, double fi) {
	N = _n;
	Fi = fi;
}

int ActionMove::DoWork(IManipulator* mn) {
	return mn->MoveElem(N, Fi);
};