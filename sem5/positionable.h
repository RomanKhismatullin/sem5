#pragma once
/// <summary>
/// ������� ����� ���������� ��������
/// </summary>

#include <complex>
using std::complex;


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
	
	
	/// <returns>0 for success, 1 failure</returns>
	virtual int SetAlpha(double A);
	/// <returns>0 for success, 1 failure</returns>
	virtual int MoveAlpha(double A);

	virtual int CanMoveAlpha(double A);
	
	virtual ~Positionable() = default;
	
	
	
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
	/// <summary>
	/// ����� ����� ��� 0 ��� ��������� �������
	/// </summary>
	/// <returns>default  - 0</returns>
	virtual double L() const;


	complex<double> drw;
	virtual complex<double> drw2();
	double drwAlpha;

protected:
	int _N;
	int _NPrev;
	double _X;
	double _Y;
	double _Alpha;
};