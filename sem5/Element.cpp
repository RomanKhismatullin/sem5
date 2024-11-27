#include "Element.h"


Element::Element(int NPrev, int N, double x, double y, double Alpha) : Positionable(NPrev, N, x, y, Alpha) {

}

void Element::SetAlpha(double A) {
	_Alpha = A;
}


void Element::MoveAlpha(double A) {
	_Alpha += A;
}


/*    
	Counter& operator += (const Counter& counter)
    {
        value += counter.value;
        return *this;   // возвращаем ссылку на текущий объект
    }
*/