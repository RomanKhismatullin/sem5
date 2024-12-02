#pragma once
#include "IAction.h"

class ActionGrip final : public IAction {
public:
	/// <summary>
	/// ƒвижени€ захвата
	/// </summary>
	/// <param name="_n">номер</param>
	/// <param name="_alpha">направление</param>
	/// <param name="_openingAlpha">положение</param>
	ActionGrip(int _n, double _alpha, double _openingAlpha);
	int DoWork(IManipulator* mn) override;

	int N;
	double Alpha;
	double OpeningAlpha;
};