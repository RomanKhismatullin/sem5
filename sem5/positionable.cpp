#include "Positionable.h"


Positionable::Positionable(int N_prev, int N, double x = 0, double y = 0, double Alpha = 0) {
	this->_X = x;
	this->_Y = y;
	this->_Alpha = Alpha;
	this->_N = N;
	this->_N_prev = N_prev;
}

int Positionable::N() const {
	return this->_N;
}

int Positionable::N_prev() const {
	return this->_N_prev;
}

double Positionable::X() const {
	return this->_X;
}

double Positionable::Y() const {
	return this->_Y;
}

double Positionable::Alpha() const {
	return this->_Alpha;
}



