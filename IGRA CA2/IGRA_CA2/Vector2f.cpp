#include "Vector2f.h"

#include "Vector3f.h"   // for knowing how to construct a Vector3f in the process of casting Vector2f to Vector3f

Vector2f::Vector2f() : x{0}, y{0}
{}

Vector2f::Vector2f(float x, float y) : x{x}, y{y}
{}

Vector2f::~Vector2f()
{}

void Vector2f::Set(float newX, float newY)
{
    this->x = newX;
    this->y = newY;
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

Vector2f::operator Vector3f() const
{
    return Vector3f(this->x, this->y, 0);
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
