#include "Vector3f.h"

#include "Vector2f.h"   // for knowing how to construct a Vector2f in the process of casting Vector3f to Vector2f

const Vector3f Vector3f::zero       { 0,  0,  0};
const Vector3f Vector3f::left       {-1,  0,  0};
const Vector3f Vector3f::right      { 1,  0,  0};
const Vector3f Vector3f::up         { 0,  1,  0};
const Vector3f Vector3f::down       { 0, -1,  0};
const Vector3f Vector3f::forward    { 0,  0,  1};
const Vector3f Vector3f::back       { 0,  0, -1};
const Vector3f Vector3f::one        { 1,  1,  1};

Vector3f::Vector3f() : x{0}, y{0}, z{0}
{}

Vector3f::Vector3f(float x, float y, float z) : x{x}, y{y}, z{z}
{}

Vector3f::~Vector3f()
{}

void Vector3f::Set(float newX, float newY, float newZ)
{
    this->x = newX;
    this->y = newY;
    this->z = newZ;
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

Vector3f::operator Vector2f() const
{
    return Vector2f(this->x, this->y);
}

Vector3f operator-(const Vector3f &vector)
{
    return Vector3f(-vector.x, -vector.y, -vector.z);
}

Vector3f operator+(const Vector3f &left, const Vector3f &right)
{
    return Vector3f(left.x + right.x, left.y + right.y, left.z + right.z);
}

Vector3f operator-(const Vector3f &left, const Vector3f &right)
{
    return Vector3f(left.x - right.x, left.y - right.y, left.z - right.z);
}

Vector3f operator*(const Vector3f &vector, float multiplier)
{
    return Vector3f(vector.x * multiplier, vector.y * multiplier, vector.z * multiplier);
}

Vector3f operator*(float multiplier, const Vector3f &vector)
{
    return Vector3f(vector.x * multiplier, vector.y * multiplier, vector.z * multiplier);
}

Vector3f operator/(const Vector3f &vector, float divisor)
{
    return Vector3f(vector.x / divisor, vector.y / divisor, vector.z / divisor);
}