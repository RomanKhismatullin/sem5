#pragma once
#include <vector>
#include <cmath>
#include <complex>
#define Point std::complex<double>
#define CB_EPS 1e-5 //точность определения углов

class solver {
public:
	static int GetIntersect(Point* L_p1, Point* L_p2, Point* Center, Point* OnRadius, double* f1, double* f2, double* t_f1, double* t_f2); // t=0 =p1, t=1 =p2
	static int CheckBetween(double d3, double d1, double d2);
	static int CheckBetween(double d3);
	static int MyEQ(double f1, double f2);

	static int IsPointOnSegment(Point* p1, Point* p2, Point* pt);
	static int CheckSegmentIntersection(Point *p1, Point *p2, Point *g1, Point *g2);
	static int CheckArcAng(double f1, double f2, double teta);
	static int CheckArc(double f1, double archL, double teta);
};