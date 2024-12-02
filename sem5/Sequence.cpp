#include "Sequence.h"


Sequence::Sequence(IManipulator* mn) {
	manipulator = mn;
	it = actions.begin();
}

void Sequence::Add(IAction* act)
{
	actions.push_back(*act);
	total++;
}

int Sequence::Next()
{
	if (it == actions.end())
		return -1;
	if ((*it).DoWork(manipulator)) {
		return static_cast<int>(total) - actions.size();
	}
	it = actions.erase(it);
	return 0;
}

int Sequence::PlayAll()
{
	return 0;
}

