#include "Element.h"


Element::Element(int NPrev, int N, double x, double y, double Alpha, double L) : Positionable(NPrev, N, x, y, Alpha) {
	_L = L;
}

double Element::L() const
{
	return _L;
}
