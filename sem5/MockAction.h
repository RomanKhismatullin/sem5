#pragma once
#include "IAction.h"
class MockAction final : public IAction {
public:
	/// <summary>
	/// ����������� ��� �����
	/// </summary>
	/// <param name="N">0 - ��� ������ (default), ����� ������ MockManipulator
	/// ����� - ������</param>
	MockAction(int N = 0, bool* DispF = nullptr);
	IAction* Clone() override;
	int N = 0;
	bool* DISPOSEFLAG = nullptr;
	
	/// <summary>
	/// ����������� ��� �����
	/// </summary>
	/// <returns>0 - success, 1 - failure</returns>
	int DoWork(IManipulator* mn) override;

	~MockAction() override;

};