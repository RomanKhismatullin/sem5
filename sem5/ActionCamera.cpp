#include "ActionCamera.h"
#include "Camera.h"

ActionCamera::ActionCamera(int n, double alphaView, double alpha) {
	this->N = n;
	this->Alpha = alpha;
	this->AlphaView = alphaView;
}

int ActionCamera::DoWork(IManipulator* mn) {
	auto s = mn->GetElement(N);
	auto ss = dynamic_cast<Camera*>(s);
	if (ss == nullptr)
		return 1;
	ss->SetAlpha(Alpha);
	ss->SetAlphaView(AlphaView);
	return 0;

}