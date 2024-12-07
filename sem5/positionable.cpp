#include "Positionable.h"


Positionable::Positionable(int N_prev, int N, double x, double y, double Alpha) {
	this->_X = x;
	this->_Y = y;
	this->_Alpha = Alpha;
	this->_N = N;
	this->_NPrev = N_prev;
}

int Positionable::N() const {
	return this->_N;
}

int Positionable::NPrev() const {
	return this->_NPrev;
}

double Positionable::L() const
{
	return 0.0;
}

int Positionable::IsNonValid() const
{
	return 0;
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


int Positionable::SetAlpha(double A) {
		this->_Alpha = A;
	return 0;
}


int Positionable::MoveAlpha(double A) {
		this->_Alpha += A;
	return 0;
}




