#include "Manipulator.h"
#include "Solver.h"


#define rotate(x, y) x*y/std::norm(y)

int Manipulator::MoveElem(int N, double fi)
{
#pragma region p_check

	if (el.size() <= N || N < 0)
		return -1; //out of range
	if (fabs(fi) > 0.99 * fi)
		return -2; //we may allow larger rotations, but they are guaranteed to cause collisions

#pragma endregion	
	if(N == 0 || N == el.size() - 1)
		return el[N]->MoveAlpha(fi);//N is at least 1 and there is at least one element after N;
	

	vector<Point> Cpoints; // non movable Points //last point is our point
	Cpoints.push_back(Point(el[0]->X(), el[0]->Y()));

	
	double totalAlpha = 0; //counts current position of element
	for (int i = 1; i <= N; i++) {
		totalAlpha += el[i - 1]->Alpha();
		Point rotator(std::polar(1.0, totalAlpha));
		Point pos(el[i]->X(), el[i]->Y());
		Cpoints.push_back(Cpoints[i-1]+pos * rotator);
	}

	Point rp = Cpoints[N]; //rotation point

	vector<Point> Rpoints; //rafius vectors of individual moved points
	

	//Point* rotP;
	//vector<Point*>* var_old;
	//vector<Point*>* var_new;


	//vector<double>* alpha_old;
	//vector<double>* alpha_new;

	//DisposeVector(var_old);
	//DisposeVector(var_new);
	//
}