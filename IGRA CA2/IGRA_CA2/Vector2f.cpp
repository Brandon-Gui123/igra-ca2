#include "Vector2f.h"

Vector2f::Vector2f() : x{values[0]}, y{values[1]}
{
    // no need to initialize the values array, because it already is initialized with 0 in all elements
}

Vector2f::Vector2f(float x, float y) : x{values[0]}, y{values[1]}
{
    values[0] = x;
    values[1] = y;
}

Vector2f::~Vector2f()
{}

void Vector2f::Set(float x, float y)
{
    this->x = x;
    this->y = y;
}
