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
	moveable(int N_prev, int N, double x, double y, double Alpha);
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
	int N() const;
	/// <summary>
	/// Номер предыдущего звена	
	/// </summary>
	int N_prev() const;
	//virtual void 
protected:
	/// <summary>
	/// Номер этого звена
	/// </summary>
	int _N;
	/// <summary>
	/// Номер предыдущего звена
	/// </summary>
	int _N_prev;

	double _X;
	double _Y;
	double _Alpha;
};
