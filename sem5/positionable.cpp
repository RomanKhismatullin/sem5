#include "Positionable.h"


Positionable::Positionable(int N_prev, int N, double x, double y, double Alpha) : TreeObj(N_prev, N) {
	this->_X = x;
	this->_Y = y;
	this->_Alpha = Alpha;
	drwAlpha = 0;
	drw = complex<double>(0.0, 0.0);
}


Positionable* Positionable::Clone()
{
	return new Positionable(*this);
}



double Positionable::L() const
{
	return 0.0;
}

complex<double> Positionable::drw2()
{
	return drw + std::polar(this->L(), this->drwAlpha);
}

void Positionable::TweekAlpha(double alph)
{
	_Alpha += alph;
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

int Positionable::CanMoveAlpha(double A)
{
	return 1;
}




