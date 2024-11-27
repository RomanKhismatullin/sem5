#include "moveable.h"


moveable::moveable(int N_prev, int N, double x = 0, double y = 0, double Alpha = 0) {
	this->_X = x;
	this->_Y = y;
	this->_Alpha = Alpha;
	this->_N = N;
	this->_N_prev = N_prev;
}

int moveable::N() const {
	return this->_N;
}

int moveable::N_prev() const {
	return this->_N_prev;
}

double moveable::X() const {
	return this->_X;
}

double moveable::Y() const {
	return this->_Y;
}

double moveable::Alpha() const {
	return this->_Alpha;
}



