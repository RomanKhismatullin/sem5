#pragma once
#include "IManipulator.h"
//#include <vector>
class MockManipulator final : public IManipulator {
public:
	Positionable* Pos = nullptr;
	//добавляет элемент 1 всегда
	int AddElement(Positionable* pos) override ; //ввод упорядочен по номеру

	//Вернет элемент добавленный Add-ом на 0, иначе nullptr
	Positionable* GetElement(int N) override; //получить по номеру

	//0 - N=0, 1 - иначе
	int MoveElem(int N, double fi) override;

	//0 - N=0, 1 - иначе
	int SetElem(int N, double fi) override;
};

