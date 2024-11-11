#include "moveable.h"


moveable::moveable(int N, int N_prev, double x, double y, double Alpha) {
	this->x = x;
	this->y = y;
	this->Alpha = Alpha;
	this->N = N;
	this->N_prev = N_prev;
}
