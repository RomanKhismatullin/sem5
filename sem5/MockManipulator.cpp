#include "MockManipulator.h"

//#include <vector>


int MockManipulator::AddElement(Positionable* pos) {
	this->Pos = pos;
	return 0;
};

Positionable* MockManipulator::GetElement(int N) {
	if (N != 0) {
		return nullptr;
	}

	return this->Pos;
};

int MockManipulator::MoveElem(int N, double fi) {
	if (N == 0) {
		Pos->MoveAlpha(fi);
		return 0;
	}
	else
		return 1;
};

int MockManipulator::SetElem(int N, double fi)
{
	if (N == 0) {
		Pos->SetAlpha(fi);
		return 0;
	}
	else
		return 1;
};
