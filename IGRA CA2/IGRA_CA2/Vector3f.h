#pragma once

// since we are casting from Vector3f to Vector2f and vice versa, Vector3f needs to know Vector2f
// but Vector2f also needs to know Vector3f.
// Without this forward declaration of the Vector3f class, the compiler cannot escape the infinite loop
// of finding out what Vector2f is.
class Vector2f;

class Vector3f
{
public:
    static const Vector3f zero;     // Shorthand writing for Vector3f{0, 0, 0}

    static const Vector3f left;     // Shorthand writing for Vector3f{-1, 0, 0}
    static const Vector3f right;    // Shorthand writing for Vector3f{1, 0, 0}

    static const Vector3f up;       // Shorthand writing for Vector3f{0, 1, 0}
    static const Vector3f down;     // Shorthand writing for Vector3f{0, -1, 0}

    static const Vector3f forward;  // Shorthand writing for Vector3f{0, 0, 1}
    static const Vector3f back;     // Shorthand writing for Vector3f{0, 0, -1}

    static const Vector3f one;      // Shorthand writing for Vector3f{1, 1, 1}

    float x;
    float y;
    float z;

    // Creates a Vector3f with all of its member fields set to 0.
    Vector3f();

    // Creates a Vector3f with the specified values.
    Vector3f(float x, float y, float z);

    ~Vector3f();

    // Sets an existing Vector3f with the specified values.
    void Set(float newX, float newY, float newZ);

    // Adds a vector to the current vector. This also returns the sum.
    Vector3f operator+=(const Vector3f &vector);
    
    // Subtracts a vector from the current vector. This also returns the difference.
    Vector3f operator-=(const Vector3f &vector);
    
    // Multiplies a vector with a scalar. This also returns the product.
    Vector3f operator*=(float multiplier);
    
    // Divides a vector with a scalar. This also returns the quotient.
    Vector3f operator/=(float divisor);

    // Implicity converts a Vector3f to a Vector2f, discarding the z member field in the process.
    operator Vector2f() const;
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
