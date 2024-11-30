#include <iostream>
#include "Positionable.h"
#include "MockManipulator.h"

int main() {
	MockManipulator* mm = new MockManipulator();
	Positionable* s = new Positionable(1, 0, 1.5, 2.5, 0);
	std::cout << s->X();
}