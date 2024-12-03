#pragma once
#include "IAction.h"
class MockAction : public IAction {
public:
	/// <summary>
	///  онструктор мок теста
	/// </summary>
	/// <param name="N">0 - дл€ успеха (default), кроме пусого MockManipulator
	/// иначе - провал</param>
	MockAction(int N = 0, bool* DispF = nullptr);
	int N = 0;
	bool* DISPOSEFLAG = nullptr;
	
	/// <summary>
	///  онструктор мок теста
	/// </summary>
	/// <returns>0 - success, 1 - failure</returns>
	int DoWork(IManipulator* mn) override;

	~MockAction() override;
};