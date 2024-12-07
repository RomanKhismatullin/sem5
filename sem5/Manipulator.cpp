#include "Manipulator.h"

Manipulator::Manipulator()
{

}



int Manipulator::AddElement(Positionable* pos)
{
	if (pos->N() != el.size())
		return 1; //wrong el
	if (pos->N() == 0 && pos->NPrev() != 0)
		return 2; //first el should start with 0
	//this way we ensure that we have individual elements
	//cause no elements can have N = a, N = b when a!=b
	el.push_back(pos);
	return 0;
}

Positionable* Manipulator::GetElement(int N)
{
	if (el.size() <= N)
		return nullptr;
	return el[N];
}



int Manipulator::SetElem(int N, double fi)
{
	if (el.size() <= N)
		return -1;
	auto t = GetElement(N);
	double diff = fi - t->Alpha();
	if (fabs(diff) > 0.99 * fi)
		return -2;
	return MoveElem(N, diff);
}

vector<Point*>* Manipulator::calc_points(Point* origin, int N_start, int N_stop)
{


	throw;
	//ѕишим динамику
	//’отим вычисл€ть очередной вектор
	//ѕосле этого вкидывать его в Solver
	//ѕосле этого провер€ть, что угол поворота хороший
	// огда доходим до конца. пишм облом или нет
	//нужно иметь отрезки, чтобы провер€ть, попадаем на них или нет
	//и нужно динамикой вычисл€ть следующую точку
	
}

void Manipulator::DisposeVector(vector<Point*>* v)
{
	auto it = v->begin();
	while (it != v->end()) {
		delete* it;
	}
	delete v;
}

