#pragma once
#include "Positionable.h"

class Element : public Positionable {
public:
	/// <summary>
	/// Создает новыйь элемент
	/// </summary>
	/// <param name="NPrev">номер предыдущего звена</param>
	/// <param name="N">номер звена</param>
	/// <param name="x">x</param>
	/// <param name="y">y</param>
	/// <param name="Alpha">угол направления</param>
	Element(int NPrev, int N, double x = 1, double y = 0, double Alpha = 0);
	/// <summary>
	/// 
	/// </summary>
	/// <param name="A"></param>
	/// <returns>0 - успех, 1 - ошибка</returns>
	void SetAlpha(double A); // в дальнейшем можно добавить ограничения по углу для каждого элемента
	void MoveAlpha(double A);
};