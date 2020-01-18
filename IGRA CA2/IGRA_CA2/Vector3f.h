#pragma once
class Vector3f
{
public:
    float x;
    float y;
    float z;

    // Creates a Vector3f with all of its member fields set to 0.
    Vector3f();

    // Creates a Vector3f with the specified values.
    Vector3f(float x, float y, float z);

    ~Vector3f();

    // Sets an existing Vector3f with the specified values.
    void Set(float x, float y, float z);

    // Adds a vector to the current vector. This also returns the sum.
    Vector3f operator+=(const Vector3f &vector);
    
    // Subtracts a vector from the current vector. This also returns the difference.
    Vector3f operator-=(const Vector3f &vector);
    
    // Multiplies a vector with a scalar. This also returns the product.
    Vector3f operator*=(float multiplier);
    
    // Divides a vector with a scalar. This also returns the quotient.
    Vector3f operator/=(float divisor);
};

