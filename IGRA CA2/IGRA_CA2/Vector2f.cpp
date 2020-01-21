#include "Vector2f.h"

#include "Vector3f.h"   // for knowing how to construct a Vector3f in the process of casting Vector2f to Vector3f
#include <cmath>        // for std::sqrt (square root) and std::pow (power)

const Vector2f Vector2f::zero   { 0,  0};
const Vector2f Vector2f::left   {-1,  0};
const Vector2f Vector2f::right  { 1,  0};
const Vector2f Vector2f::up     { 0,  1};
const Vector2f Vector2f::down   { 0, -1};
const Vector2f Vector2f::one    { 1,  1};

float Vector2f::Distance(const Vector2f &position1, const Vector2f &position2)
{
    return std::sqrt(std::pow(position1.x - position2.x, 2.f) + std::pow(position1.y - position2.y, 2.f));
}

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

float Vector2f::GetMagnitude()
{
    return std::sqrt(std::pow(this->x, 2.f) + std::pow(this->y, 2.f));
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
