#pragma once
/// <summary>
/// Базовый класс подвижного элемента
/// </summary>
class moveable {
public:
	/// <summary>
	/// Конструктор
	/// </summary>
	/// <param name="N">Номер этого звена</param>
	/// <param name="N_prev">Номер предыдущего звена</param>
	/// <param name="x">Координата X в с/к предыдущего звена</param>
	/// <param name="y">Координата Y в с/к предыдущего звена</param>
	/// <param name="Alpha">Угол относительно оси Ox предыдущего звена</param>

	moveable(int N, int N_prev, double x, double y, double Alpha);
	/// <summary>
	/// Координата X в с/к предыдущего звена
	/// </summary>
	double x;
	/// <summary>
	/// Координата Y в с/к предыдущего звена
	/// </summary>
	double y;
	/// <summary>
	/// Угол относительно оси Ox предыдущего звена
	/// </summary>
	double Alpha;
	/// <summary>
	/// Номер этого звена
	/// </summary>
	int N;
	/// <summary>
	/// Номер предыдущего звена
	/// </summary>
	int N_prev;

	//virtual void 
};
