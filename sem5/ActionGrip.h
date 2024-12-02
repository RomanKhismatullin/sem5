#pragma once
#include "IAction.h"

class ActionGrip final : public IAction {
public:
	/// <summary>
	/// �������� �������
	/// </summary>
	/// <param name="_n">�����</param>
	/// <param name="_alpha">�����������</param>
	/// <param name="_openingAlpha">���������</param>
	ActionGrip(int _n, double _alpha, double _openingAlpha);
	int DoWork(IManipulator* mn) override;

	int N;
	double Alpha;
	double OpeningAlpha;
};