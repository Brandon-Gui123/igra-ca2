#include "Vector2f.h"

Vector2f::Vector2f() : x{0}, y{0}
{}

Vector2f::Vector2f(float x, float y) : x{x}, y{y}
{}

Vector2f::~Vector2f()
{}

void Vector2f::Set(float x, float y)
{
    this->x = x;
    this->y = y;
}
