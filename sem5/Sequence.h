#pragma once
#include "IManipulator.h"
#include "IAction.h"
#include <vector>
using std::vector;
//std::vector<int>::iterator
class Sequence {
public:
	Sequence(IManipulator* mn);
	/// <summary>
	/// ����������� �����. �������� - ��������������
	/// </summary>
	/// <param name="act"></param>
	void Add(IAction* act);
	/// <summary>
	/// Plays next action
	/// </summary>
	/// <returns>0 - �����, -1 - ����� ���������, 
	/// N - ����� ��������(� 1),
	/// ��� ��������� ������ 
	/// ������������ ������ ������ ��� ������</returns>
	int Next();
	int PlayAll();
	~Sequence();
	int ActionsLeft() const;

private:
	IManipulator* manipulator;
	vector<IAction*> actions;
	int total = 0;
	
};