#include "Camera.h"

Camera::Camera(int NPrev, int N, double x, double y, double Alpha, double AlphaView) : Positionable(NPrev, N, x, y, Alpha) {
	_AlphaView = AlphaView;
}

double Camera::AlphaView() const {
	return _AlphaView;
}

void Camera::SetAlphaView(double A) {
	_AlphaView = A;
}