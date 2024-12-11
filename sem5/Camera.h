#pragma once
#include "Positionable.h"


class Camera final : public Positionable {
public:
	Camera(int N_prev, int N, double x = 0, double y = 0, double Alpha = 0, double AlphaView = 0);
	double AlphaView() const;
	void SetAlphaView(double A);
	Positionable* Clone() override;
private:
	double _AlphaView;
};