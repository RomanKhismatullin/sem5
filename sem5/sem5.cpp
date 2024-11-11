#include <iostream>
#include "moveable.h"

int main() {
	moveable* s = new moveable(1, 0, 1.5, 2.5, 0);
	std::cout << s->x;
}