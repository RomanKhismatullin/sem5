#pragma once
#include "Positionable.h"

class Element : public Positionable {
public:
	/// <summary>
	/// ������� ������ �������
	/// </summary>
	/// <param name="NPrev">����� ����������� �����</param>
	/// <param name="N">����� �����</param>
	/// <param name="x">x</param>
	/// <param name="y">y</param>
	/// <param name="Alpha">���� �����������</param>
	Element(int NPrev, int N, double x = 1, double y = 0, double Alpha = 0, double L = 1);

	double L() const override;

	Positionable* Clone() override;

protected:
	double _L;
};