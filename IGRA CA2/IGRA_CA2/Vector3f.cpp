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
    this->x += vector.x;
    this->y += vector.y;
    this->z += vector.z;

    return Vector3f(*this);
}

Vector3f Vector3f::operator-=(const Vector3f &vector)
{
    this->x -= vector.x;
    this->y -= vector.y;
    this->z -= vector.z;

    return Vector3f(*this);
}

Vector3f Vector3f::operator*=(float multiplier)
{
    this->x *= multiplier;
    this->y *= multiplier;
    this->z *= multiplier;

    return Vector3f(*this);
}

Vector3f Vector3f::operator/=(float divisor)
{
    this->x /= divisor;
    this->y /= divisor;
    this->z /= divisor;

    return Vector3f(*this);
}

Vector3f operator-(const Vector3f &vector)
{
    return Vector3f(-vector.x, -vector.y, -vector.z);
}
