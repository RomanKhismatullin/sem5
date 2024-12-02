#pragma once
#include "IAction.h"

class ActionMove final : public IAction {
public:
	ActionMove(int _n, double fi);
	int N;
	int DoWork(IManipulator* mn) override;

	double Fi;
};