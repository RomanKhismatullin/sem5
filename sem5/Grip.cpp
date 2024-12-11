#include "Grip.h"

Grip::Grip(int NPrev, int N, double x, double y, double Alpha, double OpeningAlpha) : Positionable(NPrev, N, x, y, Alpha) {
	_OpeningAlpha = OpeningAlpha;
};

double Grip::AlphaOpening() const {
	return _OpeningAlpha;
}

Positionable* Grip::Clone()
{
	return new Grip(_NPrev, _N, _X, _Y, _Alpha, _OpeningAlpha);
}

void Grip::SetOpeningAlpha(double fi) {
	_OpeningAlpha = fi;
}
