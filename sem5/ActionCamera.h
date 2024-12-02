#pragma once
#include "IAction.h"

class ActionCamera : public IAction {
public:
	ActionCamera(int n, double alpha, double alphaView);
	int DoWork(IManipulator* mn) override;

	int N;
	double Alpha;
	double AlphaView;
};