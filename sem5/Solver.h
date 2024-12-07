#pragma once
#include <vector>
#include <cmath>
#include <complex>
#define Point std::complex<double>


class solver {
public:
	static int GetIntersect(Point* L_p1, Point* L_p2, Point* Center, Point* OnRadius, double* f1, double* f2, double* t_f1, double* t_f2); // t=0 =p1, t=1 =p2
	static int CheckBetween(double d3, double d1=0, double d2=1);
	
};