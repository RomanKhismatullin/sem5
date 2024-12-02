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
	virtual int N() const final;
	/// <summary>
	/// ����� ����������� �����	
	/// </summary>
	int NPrev() const;

	/// <returns>0 for success, 1 failure</returns>
	virtual int SetAlpha(double A);
	/// <returns>0 for success, 1 failure</returns>
	virtual int MoveAlpha(double A);

protected:
	int _N;
	int _NPrev;
	double _X;
	double _Y;
	double _Alpha;
};
