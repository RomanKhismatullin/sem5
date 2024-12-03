#pragma once
#include "Element.h"
#include "Positionable.h"
#include <vector>
/// <summary>
/// �����-��������� �����������
/// </summary>
class IManipulator {
public:
	/// <summary>
	/// ���������� ��������
	/// </summary>
	/// <param name="pos">������ �� ����������� �������, ������� �� ������ ���������� ����� ����������</param>
	/// <returns>0 - �����, 1 - ������</returns>
	virtual int AddElement(Positionable* pos) = 0; //���� ���������� �� ������
	/// <summary>
	/// ��������� �������� �� ������
	/// </summary>
	/// <param name="N">����� ��������</param>
	/// <returns>������ �� �������, nullptr ���� ������ �������� ���</returns>
	virtual Positionable* GetElement(int N) = 0; //�������� �� ������

	/// <summary>
	/// ������� �������� �� �������� ����
	/// </summary>
	/// <param name="N">����� ��������, ������� ���������� ���������</param>
	/// <param name="fi">���� ��������</param>
	/// <returns>0 - �����, 1 - ������</returns>
	virtual int MoveElem(int N, double fi) = 0;
	/// <summary>
	/// ��������� �������� � �������� ���������
	/// </summary>
	/// <param name="N">����� ��������</param>
	/// <param name="fi">����, �� ������� ����������� ���������� �����</param>
	/// <returns>0 - �����, 1 - ������</returns>
	virtual int SetElem(int N, double fi) = 0;


	virtual ~IManipulator() = default;

};

