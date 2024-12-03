#pragma once
#include "IManipulator.h"
#include "IAction.h"
#include <vector>
using std::vector;
//std::vector<int>::iterator
class Sequence {
public:
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
	int PlayAll();
	~Sequence();
private:
	IManipulator* manipulator;
	vector<IAction*> actions;
	vector<IAction*>::iterator it;
	int total = 0;
	
};