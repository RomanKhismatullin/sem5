#include "ActionSet.h"

ActionSet::ActionSet(int _n, double fi) {
	N = _n;
	Fi = fi;
}

int ActionSet::DoWork(IManipulator* mn) {
	auto s = mn->GetElement(N);
	auto ss = dynamic_cast<Element*>(s);
	if (ss == nullptr)
		return 1;
	return mn->SetElem(N, Fi);
};