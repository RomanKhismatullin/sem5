#pragma once
#include "IManipulator.h"
#include "IAction.h"
#include <vector>
using std::vector;
//std::vector<int>::iterator
class Sequence final {
public:
	Sequence(const Sequence& sq) = delete; // ��������!!!

	Sequence* Clone(const Sequence* sq, IManipulator* mn);

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
	/// <summary>
	/// ��������� ��� ��������
	/// </summary>
	/// <returns>-1 - ��� �������� � ������, 
	///0 - �� �����,
	///N - �� ����� ��������, �� ������� ��������� ������ (� 1)</returns>
	int PlayAll();

	~Sequence();
	/// <summary>
	/// ������� �������� ��������
	/// </summary>

	int ActionsLeft() const;
	/// <summary>
	/// ������� �������� ���������
	/// </summary>
	int ActionsDone() const;

private:
	IManipulator* manipulator;
	vector<IAction*> actions;
	int actionCount = 0;
	
};