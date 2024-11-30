#include "ActionGrip.h"
#include "Grip.h"
ActionGrip::ActionGrip(int _n, double _alpha, double _openingAlpha) {
	N = _n;
	Alpha = _alpha;
	OpeningAlpha = _openingAlpha;
}

int ActionGrip::DoWork(IManipulator* mn) {
	auto s = mn->GetElement(N);
	Grip* ss = dynamic_cast<Grip*>(s);
	return 1;
};