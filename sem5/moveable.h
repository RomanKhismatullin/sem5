#pragma once
/// <summary>
/// ������� ����� ���������� ��������
/// </summary>
class moveable {
public:
	/// <summary>
	/// �����������
	/// </summary>
	/// <param name="N">����� ����� �����</param>
	/// <param name="N_prev">����� ����������� �����</param>
	/// <param name="x">���������� X � �/� ����������� �����</param>
	/// <param name="y">���������� Y � �/� ����������� �����</param>
	/// <param name="Alpha">���� ������������ ��� Ox ����������� �����</param>
	moveable(int N_prev, int N, double x, double y, double Alpha);
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
	/// <summary>
	/// ����� ����� �����
	/// </summary>
	int _N;
	/// <summary>
	/// ����� ����������� �����
	/// </summary>
	int _N_prev;

	double _X;
	double _Y;
	double _Alpha;
};
