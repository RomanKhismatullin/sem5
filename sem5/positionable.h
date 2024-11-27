#pragma once
/// <summary>
/// ������� ����� ���������� ��������
/// </summary>
class Positionable {
public:
	/// <summary>
	/// �����������
	/// </summary>
	/// <param name="N">����� ����� �����</param>
	/// <param name="NPrev">����� ����������� �����</param>
	/// <param name="x">���������� X � �/� ����������� �����</param>
	/// <param name="y">���������� Y � �/� ����������� �����</param>
	/// <param name="Alpha">���� ������������ ��� Ox ����������� �����</param>
	Positionable(int NPrev, int N, double x = 0, double y = 0, double Alpha = 0);
	/// <summary>
	/// ���������� X � �/� ����������� �����
	/// </summary>
	double X() const;
	/// <summary>
	/// ���������� Y � �/� ����������� �����
	/// </summary>
	double Y() const;
	/// <summary>
	/// ���� ������������ ��� Ox ����������� �����
	/// </summary>
	double Alpha() const;
	/// <summary>
	/// ����� ����� �����
	/// </summary>
	int N() const;
	/// <summary>
	/// ����� ����������� �����	
	/// </summary>
	int NPrev() const;

protected:
	int _N;
	int _NPrev;
	double _X;
	double _Y;
	double _Alpha;
};
