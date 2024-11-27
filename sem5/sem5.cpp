#include <iostream>
#include "Positionable.h"

int main() {
	Positionable* s = new Positionable(1, 0, 1.5, 2.5, 0);
	std::cout << s->X();
}