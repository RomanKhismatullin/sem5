#include "Manipulator.h"
#include "Solver.h"


#define rotate(x, y) x*y/std::norm(y)

int Manipulator::MoveElem(int N, double fi)
{

	if (el.size() <= N || N < 0)
		return -1; //out of range

	if (fabs(fi) > 2*Pi)
		return -2; //we may allow larger rotations, but they are ALMOST guaranteed to cause collisions

	if (N == 0 || N == el.size() - 1) {
		return el[N]->MoveAlpha(fi);//N is at least 1 and there is at least one element after N;
		DRW();
	}
	
	if (fabs(fi) < 2*Pi && N > 0 && N < el.size() - 1)
		return SmallRot(N, fi);

	throw;	
}


int Manipulator::SmallRot(const int N, const double fi) {
	//�� ������?
	//�������� ��������� ��������
	//��������� �� ����������� �� ���� ���������� ��� ��������
	//profit


	throw;

	DRW();
	//������������ �������� � 0 �� N-1 � ���-�� ���, ������ ���?????

	vector<Point> ps1;
	vector<Point> ps2;

	Point origin = el[N - 1]->drw; //�������� ���������� ������ ���������� ����� drw
	for (int i = N; i < el.size(); i++) {
		if (el[i]->L() == 0) // �� ������������ �������� �������
			continue;
		ps1.push_back(el[i]->drw - origin);
		ps2.push_back(el[i]->drw2() - origin);
	} // � ��� 2 ������� ����������� ������������� ����������


	for (int i = 0; i < N; i++) {
		if (el[i]->L() == 0)
			continue; //�� ������������ ��������
		for (int j = 0; j < ps1.size(); j++) {
			auto d2 = el[i]->drw2();
			int r1 = solver::CheckArchIntersection(&(el[i]->drw), &(d2), &origin, &ps1[j], fi);
			int r2 = solver::CheckArchIntersection(&(el[i]->drw), &(d2), &origin, &ps2[j], fi); //no writing
			throw;
			//int r3 = solver::CheckSegmentIntersection(&(el[i]->drw), &(d2), &ps1)
		}
	}

	
	throw;
}
