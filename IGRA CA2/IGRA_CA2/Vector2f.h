#pragma once
class Vector2f
{
public:
    float x;
    float y;

    // Constructs a Vector2f with all its member fields set to 0.
    Vector2f();

    // Constructs a Vector2f with the specified arguments.
    Vector2f(float x, float y);

    ~Vector2f();

    // Sets an existing Vector2f with the specified values.
    void Set(float x, float y);

    // Adds a vector to the current vector. This also returns the sum.
    Vector2f operator+=(const Vector2f &vector);

    // Subtracts a vector from the current vector. This also returns the difference.
    Vector2f operator-=(const Vector2f &vector);

    // Multiplies a vector with a scalar. This also returns the product.
    Vector2f operator*=(float multiplier);

    // Divides a vector with a scalar. This also returns the quotient.
    Vector2f operator/=(float divisor);
};

