#pragma once

class Vector2f
{
private:
    float values[2] { 0, 0 };

public:
    float &x;
    float &y;

    // Constructs a Vector2f with its x and y values being 0.
    Vector2f();

    // Constructs a Vector2f with the specified x and y values.
    Vector2f(float x, float y);

    ~Vector2f();

    // Sets the x and y values of an existing Vector2f with the new specified ones.
    void Set(float x, float y);
};

// Negates a vector.
Vector2f operator-(const Vector2f &vector);

// Adds 2 vectors and returns the sum.
Vector2f operator+(const Vector2f &left, const Vector2f &right);

// Subtracts a vector from another vector and returns the difference.
Vector2f operator-(const Vector2f &left, const Vector2f &right);

// Multiplies a vector with a scalar and returns the product.
Vector2f operator*(const Vector2f &vector, float multiplier);

// Multiplies a vector with a scalar and returns the product.
Vector2f operator*(float multiplier, const Vector2f &vector);       // same as previous overloaded operator*, but the multiplier comes first

// Divides a vector by a scalar and returns the quotient.
Vector2f operator/(const Vector2f &vector, float divisor);