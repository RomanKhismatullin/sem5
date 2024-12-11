#pragma once
#include "IManipulator.h"

/// <summary>
/// �����-��������� �������� ������
/// </summary>
class IAction { //��������� �� �������� �������� N (����� �����) ��� ������� ��������
public:
	/// <summary>
	/// �������� ��������
	/// </summary>
	/// <param name="mn">�����������, ������� ���������� �����������</param>
	/// <returns>0 - �����, 1 - ������</returns>
	virtual int DoWork(IManipulator* mn) = 0;

	/// <summary>
	/// ����������
	/// </summary>
	virtual ~IAction() = default;

	virtual IAction* Clone() = 0;
};