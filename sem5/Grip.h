#pragma once
#include "Positionable.h"
class Grip final : public Positionable {
public:
	Grip(int NPrev, int N, double x = 0, double y = 0, double Alpha = 0, double OpeningAlpha = 0);

	void SetOpeningAlpha(double A);

	double AlphaOpening() const;

	Positionable* Clone() override;
	
private:
	double _OpeningAlpha;
};