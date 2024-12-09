#include "Manipulator.h"
#include "Solver.h"


#define rotate(x, y) x*y/std::norm(y)

int Manipulator::MoveElem(int N, double fi)
{

	if (el.size() <= N || N < 0)
		return -1; //out of range

	if (fabs(fi) > 2*Pi)
		return -2; //we may allow larger rotations, but they are guaranteed to cause collisions

	if (N == 0 || N == el.size() - 1) {
		return el[N]->MoveAlpha(fi);//N is at least 1 and there is at least one element after N;
		DRW();
	}
	
	if (fabs(fi + el[N]->drwAlpha) < 2*Pi && fabs(el[N]->drwAlpha) < 2*Pi)
		return SmallRot(N, fi);

	throw;	
}


int Manipulator::SmallRot(int N, double fi) {
	throw;
}
