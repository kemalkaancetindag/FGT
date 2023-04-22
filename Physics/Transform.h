#pragma once
#include "Vector2D.h"

class Transform {
public:
	float X, Y;
public:
	Transform(float x = 0, float y = 0) : X(x), Y(y) {}
private:
	inline void TranslateX(float x) { X += x; }
	inline void TranslateY(float y) { X += y; }
	inline void Translate(Vector2D v) { X += v.X; Y += v.Y; }
};