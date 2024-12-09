#pragma once
#include <vector>
#include <cmath>
#include <complex>
#define Point std::complex<double>
#define CB_EPS 1e-5 //�������� ����������� �����

class solver {
public:
	/// <summary>
	/// ������� ���������� � ������ �� �������
	/// </summary>
	/// <returns>����� ����� �����������</returns>
	static int GetIntersect(const Point* L_p1, const Point* L_p2, const Point* Center, const Point* OnRadius, double* f1, double* f2, double* t_f1, double* t_f2); // t=0 =p1, t=1 =p2

	/// <summary> </summary>
	/// <returns>1 - ���� �����, 0 - ���� ���</returns>
	static int CheckBetween(double d3, double d1, double d2);
	/// <summary> </summary>
	/// <returns>1 - ���� �����, 0 - ���� ���</returns>
	static int CheckBetween(double d3);

	static int MyEQ(double f1, double f2);
	/// <summary> </summary>
	/// <returns>1 - ���� �����, 0 - ���� ���</returns>
	static int CheckArcAng(double f1, double f2, double teta);
	/// <summary> </summary>
	/// <returns>1 - ���� �����, 0 - ���� ���</returns>
	static int CheckArc(double f1, double archL, double teta);

	static int CheckSegmentIntersection(const Point* p1, const Point* p2, const Point* g1, const Point* g2); //������� ������� ����������� ���� �������� (��� ������) 
	static int CheckArchIntersection(const Point* L_p1, const Point* L_p2, const Point* origin, const Point* OnRadius, double alpha);//������� ������� �������� ����������� ���� � �������
};