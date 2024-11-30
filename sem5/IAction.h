#pragma once
#include "IManipulator.h"

/// <summary>
/// �����-��������� �������� ������
/// </summary>
class IAction {
public:
	/// <summary>
	/// �������� ��������
	/// </summary>
	/// <param name="mn">�����������, ������� ���������� �����������</param>
	/// <returns>0 - �����, 1 - ������</returns>
	virtual int DoWork(IManipulator* mn) = 0;
};