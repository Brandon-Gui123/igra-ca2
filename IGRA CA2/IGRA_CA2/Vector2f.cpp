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
    this->x += vector.x;
    this->y += vector.y;

    return Vector2f(*this);
}

Vector2f Vector2f::operator-=(const Vector2f &vector)
{
    this->x -= vector.x;
    this->y -= vector.y;

    return Vector2f(*this);
}

Vector2f Vector2f::operator*=(float multiplier)
{
    this->x *= multiplier;
    this->y *= multiplier;

    return Vector2f(*this);
}

Vector2f Vector2f::operator/=(float divisor)
{
    this->x /= divisor;
    this->y /= divisor;

    return Vector2f(*this);
}

Vector2f operator-(const Vector2f &vector)
{
}
