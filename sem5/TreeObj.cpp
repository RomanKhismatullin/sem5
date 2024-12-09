#include "TreeObj.h"

TreeObj::TreeObj(int NPrev, int N)
{
	_NPrev = NPrev;
	_N = N;
}

int TreeObj::N() const {
	return this->_N;
}

int TreeObj::NPrev() const {
	return this->_NPrev;
}