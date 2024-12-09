#pragma once
#include <vector>
#include <cmath>
#include "Element.h"
#include "IManipulator.h"
using std::vector;
using std::min;
using std::fabs;
#define Pi 3.14159265358979323846
#include <complex>
#define Point std::complex<double>

class Manipulator final : public IManipulator {
public:

	Manipulator();


	/// <summary>
	/// Adds Element
	/// </summary>
	/// <param name="pos">posistionable to add</param>
	/// <returns>0 - success, 1 - on failure, -2 - failure arg>pi*0.99 err</returns>
	int AddElement(Positionable* pos) override;
	Positionable* GetElement(int N) override;



	/// <summary>
	/// �������� ������� �� ���� �� [-pi;pi]
	/// </summary>
	/// <param name="N"></param>
	/// <param name="fi"></param>
	/// <returns></returns>
	int MoveElem(int N, double fi) override;
	/// <summary>
	/// Play
	/// </summary>
	/// <returns>Returns -1, on no element; </returns>
	int SetElem(int N, double fi) override;


	void DRW();

private:
	vector<Positionable*> el;//��������, ������ ��������� ���-�� �������
	void DisposeVector(vector<Point*>* v);
	int SmallRot(int N, double fi); //�������� �� ���� ������ Pi
	double collision = 0;
	double N_collision = 0;
};