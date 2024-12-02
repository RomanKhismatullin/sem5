#pragma once
#include "IAction.h"

class ActionSet final : public IAction {
public:
	ActionSet(int _n, double fi);
	int DoWork(IManipulator* mn) override;

	int N;
	double Fi;
};