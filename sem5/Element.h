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
	Element(int NPrev, int N, double x = 1, double y = 0, double Alpha = 0);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="A"></param>
	/// <returns>0 - �����, 1 - ������</returns>
	void SetAlpha(double A); // � ���������� ����� �������� ����������� �� ���� ��� ������� ��������
	void MoveAlpha(double A);
};