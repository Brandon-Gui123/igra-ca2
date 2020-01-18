#include "Vector3f.h"

Vector3f::Vector3f() : x{0}, y{0}, z{0}
{}

Vector3f::Vector3f(float x, float y, float z) : x{x}, y{y}, z{z}
{}

Vector3f::~Vector3f()
{}

void Vector3f::Set(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3f Vector3f::operator+=(const Vector3f &vector)
{
}

Vector3f Vector3f::operator-=(const Vector3f &vector)
{
}

Vector3f Vector3f::operator*=(float multiplier)
{
}

Vector3f Vector3f::operator/=(float divisor)
{
}
