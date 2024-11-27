#pragma once
#include "Positionable.h"
class Grip final : public Positionable {
public:
	/// <summary>
	/// �����������
	/// </summary>
	/// <param name="N">����� ����� �����</param>
	/// <param name="N_prev">����� ����������� �����</param>
	/// <param name="x">���������� X � �/� ����������� �����</param>
	/// <param name="y">���������� Y � �/� ����������� �����</param>
	/// <param name="Alpha">���� ������������ ��� Ox ����������� �����</param>
	Grip(int N_prev, int N, double x = 0, double y = 0, double Alpha = 0, double OpeningAlpha = 0);

	void SetOpeningAlpha(double A);

	double OpeningAlpha() const;
private:
	double _OpeningAlpha;
};