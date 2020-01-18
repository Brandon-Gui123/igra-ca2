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

// Negates a vector.
Vector3f operator-(const Vector3f& vector);

// Adds two vectors and returns the sum.
Vector3f operator+(const Vector3f& left, const Vector3f& right);

// Subtracts the right vector from the left vector and returns the difference.
Vector3f operator-(const Vector3f& left, const Vector3f& right);

// Multiplies a vector with a number and returns the product.
Vector3f operator*(const Vector3f& vector, float multiplier);

// Multiplies a vector with a number and returns the product.
Vector3f operator*(float multiplier, const Vector3f& vector);   // same as overload for operator*(Vector3f, float), but this is for when the order of arguments is flipped

// Divides a vector with a number and returns the quotient.
Vector3f operator/(const Vector3f& vector, float divisor);
