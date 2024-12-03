#pragma once
#include "Element.h"
#include "Positionable.h"
#include <vector>
/// <summary>
/// Класс-интерфейс манпулятора
/// </summary>
class IManipulator {
public:
	/// <summary>
	/// Добавление элемениа
	/// </summary>
	/// <param name="pos">ссылка на добавляемый элемент, элемент не должен изменяться после добавления</param>
	/// <returns>0 - успех, 1 - ошибка</returns>
	virtual int AddElement(Positionable* pos) = 0; //ввод упорядочен по номеру
	/// <summary>
	/// Получнеие элемента по номеру
	/// </summary>
	/// <param name="N">Номер элемента</param>
	/// <returns>Ссылку на элемент, nullptr если такого элемента нет</returns>
	virtual Positionable* GetElement(int N) = 0; //получить по номеру

	/// <summary>
	/// Поворот элементп на заданный угол
	/// </summary>
	/// <param name="N">Номер элемента, который необходимо повернуть</param>
	/// <param name="fi">Угол поворота</param>
	/// <returns>0 - успех, 1 - ошибка</returns>
	virtual int MoveElem(int N, double fi) = 0;
	/// <summary>
	/// Установка элемента в заданное положение
	/// </summary>
	/// <param name="N">Номер элемента</param>
	/// <param name="fi">Угол, на который необходимос установить звено</param>
	/// <returns>0 - успех, 1 - ошибка</returns>
	virtual int SetElem(int N, double fi) = 0;


	virtual ~IManipulator() = default;

};

