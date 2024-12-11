#pragma once
#include "IManipulator.h"
#include "IAction.h"
#include <vector>
using std::vector;
//std::vector<int>::iterator
class Sequence final {
public:
	Sequence(const Sequence& sq) = delete; // запещаем!!!

	Sequence* Clone(const Sequence* sq, IManipulator* mn);

	Sequence(IManipulator* mn);
	/// <summary>
	/// Регистрация здесь. Удаление - автоматическое
	/// </summary>
	/// <param name="act"></param>
	void Add(IAction* act);
	/// <summary>
	/// Plays next action
	/// </summary>
	/// <returns>0 - успех, -1 - конец программы, 
	/// N - номер действия(с 1),
	/// где произошлв ошибка 
	/// Освобождение памяти только при успехе</returns>
	int Next();
	/// <summary>
	/// Выполняет все действия
	/// </summary>
	/// <returns>-1 - нет действий в списке, 
	///0 - на успех,
	///N - на номер действия, на котором произошла ошибка (с 1)</returns>
	int PlayAll();

	~Sequence();
	/// <summary>
	/// Сколько действий записано
	/// </summary>

	int ActionsLeft() const;
	/// <summary>
	/// Сколько действий выполнено
	/// </summary>
	int ActionsDone() const;

private:
	IManipulator* manipulator;
	vector<IAction*> actions;
	int actionCount = 0;
	
};