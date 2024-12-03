#include "Sequence.h"


Sequence::Sequence(IManipulator* mn) {
	manipulator = mn;
	it = actions.begin();
}

void Sequence::Add(IAction* act)
{
	actions.push_back(act);
	total++;
}

int Sequence::Next()
{
	if (it == actions.end())
		return -1;
	if ((*it)->DoWork(manipulator)) {
		return static_cast<int>(total) - actions.size();
	}
	delete (*it);
	it = actions.erase(it);
	return 0;
}

int Sequence::PlayAll()
{
	return 0;
}

Sequence::~Sequence() {
	// Iterate using the iterator
	for (auto it_ = actions.begin(); it != actions.end(); ++it) {
		(*it_)->~IAction();
	}
}