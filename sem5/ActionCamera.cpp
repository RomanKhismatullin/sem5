#include "ActionCamera.h"
#include "Camera.h"

ActionCamera::ActionCamera(int n, double alpha, double alphaView) {
	this->N = n;
	this->Alpha = alpha;
	this->AlphaView = alphaView;
}

int ActionCamera::DoWork(IManipulator* mn) {
	auto s = mn->GetElement(N);
	auto ss = dynamic_cast<Camera*>(s);
	if (ss == nullptr)
		return 1;
	s->SetAlpha(Alpha);
	ss->SetAlphaView(AlphaView);
	return 0;
}

IAction* ActionCamera::Clone()
{
	return new ActionCamera(*this);
}
