#pragma once
#include "IManipulator.h"

/// <summary>
/// Класс-интерфейс действие робота
/// </summary>
class IAction { //НАМЕРЕННО НЕ ДОБАВЛЕН ПАРАМЕТР N (номер звена) для большей гибкости
public:
	/// <summary>
	/// Выплнить действие
	/// </summary>
	/// <param name="mn">манипулятор, который необходимо переместить</param>
	/// <returns>0 - успех, 1 - ошибка</returns>
	virtual int DoWork(IManipulator* mn) = 0;

	/// <summary>
	/// Деструктор
	/// </summary>
	virtual ~IAction() = default;

	virtual IAction* Clone() = 0;
};