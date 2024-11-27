#include "Grip.h"

Grip::Grip(int N_prev, int N, double x, double y, double Alpha, double OpeningAlpha) : Positionable(N_prev, N, x, y, Alpha) {
	_OpeningAlpha = OpeningAlpha;
};

double Grip::OpeningAlpha() const {
	return _OpeningAlpha;
}

void Grip::SetOpeningAlpha(double fi) {
	_OpeningAlpha = fi;
}
