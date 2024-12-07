#include "pch.h"
#include <vector>
#include <complex>
#include "../sem5/Element.h"

using std::vector;
using std::complex;
#define Point complex<double>
#define MM_PI 3.141592653589793

TEST(ManipulatorTest, MoveElementGettingConstPoints) {
#pragma region prms
	const int N = 5;
	vector<Element*> el;
	//el.push_back(new el(0, 0));
	//el.push_back(new el(0, 0, ));
#pragma endregion

	vector<Point> Cpoints; // non movable Points //last point is our point
	Cpoints.push_back(Point(el[0]->X(), el[0]->Y()));


	double totalAlpha = 0; //counts current position of element
	for (int i = 1; i <= N; i++) {
		totalAlpha += el[i - 1]->Alpha();
		Point rotator(std::polar(1.0, totalAlpha));
		Point pos(el[i]->X(), el[i]->Y());
		Cpoints.push_back(Cpoints[i - 1] + pos * rotator);
	}

	Point rp = Cpoints[N]; //rotation point

	



}