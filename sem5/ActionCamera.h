#pragma once
#include "IAction.h"

class ActionCamera final : public IAction {
public:
	ActionCamera(int n, double alpha, double alphaView);
	int DoWork(IManipulator* mn) override;
	IAction* Clone() override;


	int N;
	double Alpha;
	double AlphaView;

};