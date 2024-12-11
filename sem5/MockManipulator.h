#pragma once
#include "IManipulator.h"
//#include <vector>



/// <summary>
/// ����� ��� ���-������ IAction
/// </summary>
class MockManipulator final : public IManipulator {
public:
	bool* DISPOSEDFLAG = nullptr;
	Positionable* Pos = nullptr;
	//��������� ������� 1 ������
	int AddElement(Positionable* pos) override ; //���� ���������� �� ������

	//������ ������� ����������� Add-�� �� 0, ����� nullptr
	Positionable* GetElement(int N) override; //�������� �� ������

	//0 - N=0, 1 - �����
	int MoveElem(int N, double fi) override;

	//0 - N=0, 1 - �����
	int SetElem(int N, double fi) override;

	~MockManipulator() override;
};

