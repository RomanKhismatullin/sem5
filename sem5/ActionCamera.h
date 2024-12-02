#pragma once
#include "IAction.h"

class ActionCamera : public IAction {
public:
	ActionCamera(int n, double alphaView, double alpha);
	int DoWork(IManipulator* mn) override;
	int N;
	double Alpha;
	double AlphaView;
};