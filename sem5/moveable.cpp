#include "moveable.h"


moveable::moveable(int N_prev, int N) {
	this->n = N;
	this->n_prev = N_prev;
}

moveable::moveable(int N_prev, int N, double x, double y, double Alpha) {
	this->x = x;
	this->y = y;
	this->Alpha = Alpha;
	this->n = N;
	this->n_prev = N_prev;
}

int moveable::N() {
	return this->n;
}

int moveable::N_prev() {
	return this->n_prev;
}