#pragma once
#include <vector>
#include <cmath>
#include "Element.h"
#include "IManipulator.h"
#include "GraphSolver.h"
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
	/// Сдвиагет элемент на угол от [-pi;pi]
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

	/// <summary>
	/// Отрисовка
	/// </summary>
	void DRW();

	/// <summary>
	/// Отрисовка с [N, ...]
	/// </summary>
	/// <param name="N">Первый перерисуемый</param>
	void DRW(int N);


	double collision = 0;
	double Const_collision = 0;
	double Moved_collision = 0;
	double Elem_collision = 0;

private:
	vector<Positionable*> el;//приватен, ссылки храняться где-то снаружи
	void DisposeVector(vector<Point*>* v);
	int SmallRot(const int N, const double fi); //повороты на углы меньше Pi

};