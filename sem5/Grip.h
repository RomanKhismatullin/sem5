#pragma once
#include "Element.h"
class Grip final : public Element {
public:
	Grip(int NPrev, int N, double x = 0, double y = 0, double Alpha = 0, double OpeningAlpha = 0);

	void SetOpeningAlpha(double A);

	double AlphaOpening() const;
private:
	double _OpeningAlpha;
};