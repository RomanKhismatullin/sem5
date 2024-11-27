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
	/// <param name="N_prev">����� ����������� �����</param>
	/// <param name="x">���������� X � �/� ����������� �����</param>
	/// <param name="y">���������� Y � �/� ����������� �����</param>
	/// <param name="Alpha">���� ������������ ��� Ox ����������� �����</param>
	Positionable(int N_prev, int N, double x = 0, double y = 0, double Alpha = 0);
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
	int N_prev() const;
	//virtual void 
protected:
	int _N;
	int _N_prev;
	double _X;
	double _Y;
	double _Alpha;
};
