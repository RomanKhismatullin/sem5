#pragma once
#include "IAction.h"

class ActionMove final : public IAction {
public:
	ActionMove(int _n, double fi);
	int DoWork(IManipulator* mn) override;
	IAction* Clone() override;


	int N;
	double Fi;
};