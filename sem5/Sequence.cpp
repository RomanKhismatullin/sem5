#include "Sequence.h"


Sequence::Sequence(IManipulator* mn) {
	manipulator = mn;
}

void Sequence::Add(IAction* act)
{
	actions.push_back(act);
	total++;
}

int Sequence::Next()
{

	if (actions.empty())
		return -1;

	auto it = actions.begin();

	auto rs = (*it)->DoWork(manipulator);
	if (rs != 0) {
		return 1;
	}

	delete (*it);
	actions.erase(it);
	return 0;
}	

int Sequence::PlayAll()
{
	return 0;
}

Sequence::~Sequence() {
	// Iterate using the iterator
	for (auto it_ = actions.begin(); it_ != actions.end(); ++it_) {
		delete *it_;
	}
	delete manipulator;
}

int Sequence::ActionsLeft() const
{
	return static_cast<int>(actions.size());
}
