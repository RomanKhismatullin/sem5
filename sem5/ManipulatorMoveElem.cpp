#include "Manipulator.h"
#include "Solver.h"
#include "GraphSolver.h"
#include "GraphSolver.cpp"


#include <iostream>

#define rotate(x, y) x*y/std::norm(y)

int Manipulator::MoveElem(int N, double fi)
{

	if (fi == 0)
		return 0;

	if (el.size() <= N || N < 0)
		return -1; //out of range

	if (fabs(fi) > 2*Pi)
		return -2; //we may allow larger rotations, but they are ALMOST guaranteed to cause collisions

	if (N == 0) {
		int rs = el[N]->MoveAlpha(fi);//N is at least 1 and there is at least one element after N;
		if(!rs)
			DRW();
		return rs;
	}
	
	if (fabs(fi) < 2 * Pi && N > 0)
		return SmallRot(N, fi);

	throw;	
}


int Manipulator::SmallRot(const int N, const double fi) {

	if (!el[N]->CanMoveAlpha(fi)) {
		collision = 1;
		Const_collision = 0;
		Moved_collision = 0;
		return -1;
	}

	//чо делаем?
	//GSolver - выделяем подвижные элементы
	//GSolver - выделяем НЕподвижные элементы
	//проверяем их пересечения при движении
	//profit

	DRW();

	//Неподвижными остаются с 0 по N-1 и кто-то ещё, вопрос кто?????

	vector<Positionable*> Moved;
	vector<Positionable*> Const;
	int rs = GSolver::BuildPredecessorBranch(el, N, Moved, Const);
	//for (int i = 0; i < rs; i++) { //Потенциально опасный код!!!
	//	if (Moved[i]->L() == 0) {
	//		Moved.erase(Moved.begin() + i);//удалили
	//		rs--;
	//		i--;
	//	}
	//}
	//rs = Const.size();
	//for (int i = 0; i < rs; i++) {
	//	if (Moved[i]->L() == 0) {
	//		Const.erase(Const.begin() + i);//удалили
	//		rs--;
	//		i--;
	//	}
	//}


	auto origin = el[N]->drw; // центр вращения
	for (int i = 0; i < Moved.size(); i++) {
		if (Moved[i]->L() == 0)
			continue;
		for (int j = 0; j < Const.size(); j++) {
			if (Const[j]->L() == 0)
				continue;
			auto m1 = Moved[i]->drw;
			auto m2 = Moved[i]->drw2();

			auto c1 = Const[j]->drw;
			auto c2 = Const[j]->drw2();

			int rt1 = solver::CheckArchIntersection(&c1, &c2, &origin, &m1, fi);
			int rt2 = solver::CheckArchIntersection(&c1, &c2, &origin, &m2, fi);
			if (rt1 || rt2) {
				this->collision = 1;
				this->Const_collision = Const[j]->N();
				this->Moved_collision = Moved[i]->N();
				this->Elem_collision = 0;
				return 1;
			}
		}
	}

	//Еще хорошо бы повернуть и проверить отрезки (позже сделаем)
	el[N]->TweekAlpha(fi);
	DRW();
	el[N]->TweekAlpha(-fi);
	for (int i = 0; i < Moved.size(); i++) {
		if (Moved[i]->L() == 0)
			continue;
		for (int j = 0; j < Const.size(); j++) {
			if (Const[j]->L() == 0)
				continue;

			auto m1 = Moved[i]->drw;
			auto m2 = Moved[i]->drw2();

			auto c1 = Const[j]->drw;
			auto c2 = Const[j]->drw2();

			int rt1 = solver::CheckSegmentIntersection(&m1, &m2, &c1, &c2);
			if (rt1) {
				this->collision = 1;
				this->Const_collision = Const[j]->N();
				this->Moved_collision = Moved[i]->N();
				this->Elem_collision = 1;
				return 1;
			}
		}
	}

	// ....

	///Закругляемся
	
	el[N]->MoveAlpha(fi);
	return 0;
}
