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

Vector2f Vector2f::operator+=(const Vector2f &other)
{
    this->x += other.x;
    this->y += other.y;
    return Vector2f(*this);
}

Vector2f Vector2f::operator-=(const Vector2f &other)
{
    this->x -= other.x;
    this->y -= other.y;
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
    return Vector2f(-vector.x, -vector.y);
}

Vector2f operator+(const Vector2f &left, const Vector2f &right)
{
    return Vector2f(left.x + right.x, left.y + right.y);
}

Vector2f operator-(const Vector2f &left, const Vector2f &right)
{
    return Vector2f(left.x - right.x, left.y - right.y);
}

Vector2f operator*(const Vector2f &vector, float multiplier)
{
    return Vector2f(vector.x * multiplier, vector.y * multiplier);
}

Vector2f operator*(float multiplier, const Vector2f &vector)
{
    return Vector2f(vector.x * multiplier, vector.y * multiplier);
}

Vector2f operator/(const Vector2f &vector, float divisor)
{
    return Vector2f(vector.x / divisor, vector.y / divisor);
}
