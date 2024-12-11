#include "Manipulator.h"

Manipulator::Manipulator()
{

}

#define CPY(A) A=m.A

Manipulator::Manipulator(const Manipulator& m)
{
	CPY(collision);
	CPY(Const_collision);
	CPY(Moved_collision);
	CPY(Elem_collision);
	el.resize(m.el.size());
	for (auto e : m.el) {
		el.push_back(e->Clone());
	}
}

Manipulator& Manipulator::operator=(const Manipulator& m)
{

	if (&m == this)
	{
		return *this;
	}

	this->~Manipulator();

	CPY(collision);
	CPY(Const_collision);
	CPY(Moved_collision);
	CPY(Elem_collision);
	el.resize(m.el.size());
	for (auto e : m.el) {
		el.push_back(e->Clone());
	}
}

Manipulator::~Manipulator()
{
	for (auto e : el)
		delete e;
	el.clear();
}

int Manipulator::AddElement(Positionable* pos)
{
	if (pos->N() != el.size())
		return 1; //wrong el
	if (pos->N() == 0 && pos->NPrev() != 0)
		return 2; //first el should start with 0

	if (pos->NPrev() > pos->N() || pos->NPrev() < 0)
		return 3;

	if (fabs(pos->Alpha()) > 2 * Pi)
		return 4;

	if (pos->L() < 0)
		return 5;


	//this way we ensure that we have individual elements
	//cause no elements can have N = a, N = b when a!=b
	el.push_back(pos);
	return 0;
}

Positionable* Manipulator::GetElement(int N)
{
	if (el.size() <= N || N < 0)
		return nullptr;
	return el[N];
}

int Manipulator::GetElementsSize() const
{
	return (int)el.size();
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

void Manipulator::DRW()
{
	el[0]->drw = Point(el[0]->X(), el[0]->Y());//Зарисовали вектор первой точки
	el[0]->drwAlpha = el[0]->Alpha(); //Задан первый элемент


	for (int i = 1; i < el.size(); i++) {


		double p_drwalpha = el[el[i]->NPrev()]->drwAlpha;
		Point p_drw = el[el[i]->NPrev()]->drw;

		Point mv = Point(el[i]->X(), el[i]->Y()); //offset
		Point rot = Point(std::cos(p_drwalpha), std::sin(p_drwalpha));//Берем ориентацию предыдущей точки



		el[i]->drwAlpha = p_drwalpha + el[i]->Alpha();
		el[i]->drw = el[el[i]->NPrev()]->drw + rot * mv; //z_0 + rot * z
	}
}

void Manipulator::DRW(int N)
{
	if (N == 0) {
		DRW();
		return;
	}
	else
		for (int i = N; i < el.size(); i++) {
			double p_drwalpha = el[el[i]->NPrev()]->drwAlpha;
			Point p_drw = el[el[i]->NPrev()]->drw;

			Point mv = Point(el[i]->X(), el[i]->Y()); //offset
			Point rot = Point(std::cos(p_drwalpha), std::sin(p_drwalpha));//Берем ориентацию предыдущей точки



			el[i]->drwAlpha = p_drwalpha + el[i]->Alpha();
			el[i]->drw = el[el[i]->NPrev()]->drw + rot * mv; //z_0 + rot * z
		}
}


