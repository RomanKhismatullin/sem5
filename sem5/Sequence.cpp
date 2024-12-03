#include "Sequence.h"


Sequence::Sequence(IManipulator* mn) {
	manipulator = mn;
}

void Sequence::Add(IAction* act)
{
	actions.push_back(act);
}

int Sequence::Next()
{
	actionCount++;
	if (actions.empty())
		return -1;

	auto it = actions.begin();

	auto rs = (*it)->DoWork(manipulator);
	if (rs != 0) {
		return actionCount;
	}

	delete (*it);
	actions.erase(it);
	return 0;
}	

int Sequence::PlayAll()
{
	for (auto it_ = actions.begin(); it_ != actions.end(); ++it_) {
		auto s = (*it_)->DoWork(manipulator);
		if (s != 0) {
			return actionCount;
		}
	}
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

int Sequence::ActionsDone() const
{
	return actionCount;
}
