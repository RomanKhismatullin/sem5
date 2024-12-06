#include "Manipulator.h"

#include "Solver.h"


int Manipulator::MoveElem(int N, double fi)
{
#pragma region p_check
	if (el.size() <= N)
		return -1;
	if (fabs(fi) > 0.99 * fi)
		return -2; //we may allow larger rotations, but they are guaranteed to cause collisions

#pragma endregion
	if (N == 0 || N == el.size() - 1)
		return el[0]->MoveAlpha(fi);//N is at least 1 and there is at least one element after N;

	vector<Point*>* pts = new vector<Point*>();
	pts->push_back(new Point(el[0]->X(), el[0]->Y()));

	//Point* t = new Point(el[0]->)
	for (int i = 1; i <= N; i++) {
		Point dir = std::norm(el[i - 1]);

		Point* p = new Point(el[i]->X(), el[i]->Y());
		p->
	}

	
		
	DisposeVector(pts);


	//Point* rotP;
	//vector<Point*>* var_old;
	//vector<Point*>* var_new;


	//vector<double>* alpha_old;
	//vector<double>* alpha_new;

	//DisposeVector(var_old);
	//DisposeVector(var_new);
	//
}