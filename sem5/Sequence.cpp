#include "Sequence.h"


Sequence* Sequence::Clone(const Sequence* sq, IManipulator* mn)
{
	auto t = new Sequence(mn);
	t->actionCount = actionCount;
	t->actions.resize(actions.size());
	for (auto e : actions) {
		t->actions.push_back(e->Clone());
	}
	return t;
}

Sequence::Sequence(IManipulator* mn) {
	manipulator = mn;
}

void Sequence::Add(IAction* act)
{
	actions.push_back(act);
}

int Sequence::Next()
{
	if (actions.empty())
		return -1;
	actionCount++;

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
	return 0;
}

Sequence::~Sequence() {
	// Iterate using the iterator
	for (auto it_ = actions.begin(); it_ != actions.end(); ++it_) {
		delete *it_;
	}
	//delete manipulator; //OR SHOULD WE?
}

int Sequence::ActionsLeft() const
{
	return static_cast<int>(actions.size());
}

int Sequence::ActionsDone() const
{
	return actionCount;
}
