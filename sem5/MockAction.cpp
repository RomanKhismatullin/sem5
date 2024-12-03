#include "MockAction.h"

MockAction::MockAction(int N, bool* DispF)
{
	DISPOSEFLAG = DispF;
	this->N = N;
}

int MockAction::DoWork(IManipulator* mn)
{
	//return 1;
	if (N != 0)
		return 1;

	auto i = mn->GetElement(N);

	if (i == nullptr)
		return 1;

	i->MoveAlpha(1);
	return 0;
}

MockAction::~MockAction()
{
	if (DISPOSEFLAG != nullptr) {
		*DISPOSEFLAG = true;
	}
}
