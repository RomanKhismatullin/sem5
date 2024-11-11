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

	moveable(int N, int N_prev, double x, double y, double Alpha);
	/// <summary>
	/// ���������� X � �/� ����������� �����
	/// </summary>
	double x;
	/// <summary>
	/// ���������� Y � �/� ����������� �����
	/// </summary>
	double y;
	/// <summary>
	/// ���� ������������ ��� Ox ����������� �����
	/// </summary>
	double Alpha;
	/// <summary>
	/// ����� ����� �����
	/// </summary>
	int N;
	/// <summary>
	/// ����� ����������� �����
	/// </summary>
	int N_prev;

	//virtual void 
};
