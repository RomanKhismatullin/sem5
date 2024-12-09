#pragma once
/// <summary>
/// Базовый класс подвижного элемента
/// </summary>

#include <complex>
using std::complex;


class Positionable {
public:
	/// <summary>
	/// Конструктор
	/// </summary>
	/// <param name="N">Номер этого звена</param>
	/// <param name="NPrev">Номер предыдущего звена</param>
	/// <param name="x">Координата X в с/к предыдущего звена</param>
	/// <param name="y">Координата Y в с/к предыдущего звена</param>
	/// <param name="Alpha">Угол относительно оси Ox предыдущего звена</param>
	Positionable(int NPrev, int N, double x = 0, double y = 0, double Alpha = 0);
	
	
	/// <returns>0 for success, 1 failure</returns>
	virtual int SetAlpha(double A);
	/// <returns>0 for success, 1 failure</returns>
	virtual int MoveAlpha(double A);

	virtual int CanMoveAlpha(double A);
	
	virtual ~Positionable() = default;
	
	
	
	/// <summary>
	/// Координата X в с/к предыдущего звена
	/// </summary>
	double X() const;
	/// <summary>
	/// Координата Y в с/к предыдущего звена
	/// </summary>
	double Y() const;
	/// <summary>
	/// Угол относительно оси Ox предыдущего звена
	/// </summary>
	double Alpha() const;
	/// <summary>
	/// Номер этого звена
	/// </summary>
	virtual int N() const final;
	/// <summary>
	/// Номер предыдущего звена	
	/// </summary>
	int NPrev() const;
	/// <summary>
	/// Длина звена или 0 для точечного объекта
	/// </summary>
	/// <returns>default  - 0</returns>
	virtual double L() const;


	complex<double> drw;
	virtual complex<double> drw2();
	double drwAlpha;

protected:
	int _N;
	int _NPrev;
	double _X;
	double _Y;
	double _Alpha;
};