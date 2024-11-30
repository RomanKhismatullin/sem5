#include "ActionSet.h"

ActionSet::ActionSet(int _n, double fi) {
	N = _n;
	Fi = fi;
}

int ActionSet::DoWork(IManipulator* mn) {
	return mn->SetElem(N, Fi);
};