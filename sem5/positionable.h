#pragma once
/// <summary>
/// Базовый класс подвижного элемента
/// </summary>
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

	/// <returns>0 for success, 1 failure</returns>
	virtual int SetAlpha(double A);
	/// <returns>0 for success, 1 failure</returns>
	virtual int MoveAlpha(double A);

protected:
	int _N;
	int _NPrev;
	double _X;
	double _Y;
	double _Alpha;
};
