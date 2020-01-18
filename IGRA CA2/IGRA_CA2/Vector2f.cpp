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

Vector2f Vector2f::operator+=(const Vector2f &vector)
{
}

Vector2f Vector2f::operator-=(const Vector2f &vector)
{
}

Vector2f Vector2f::operator*=(float multiplier)
{
}

Vector2f Vector2f::operator/=(float divisor)
{
}
