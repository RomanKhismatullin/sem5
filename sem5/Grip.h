#pragma once
#include "Positionable.h"
class Grip final : public Positionable {
public:
	/// <summary>
	/// Конструктор
	/// </summary>
	/// <param name="N">Номер этого звена</param>
	/// <param name="N_prev">Номер предыдущего звена</param>
	/// <param name="x">Координата X в с/к предыдущего звена</param>
	/// <param name="y">Координата Y в с/к предыдущего звена</param>
	/// <param name="Alpha">Угол относительно оси Ox предыдущего звена</param>
	Grip(int N_prev, int N, double x = 0, double y = 0, double Alpha = 0, double OpeningAlpha = 0);

	void SetOpeningAlpha(double A);

	double OpeningAlpha() const;
private:
	double _OpeningAlpha;
};