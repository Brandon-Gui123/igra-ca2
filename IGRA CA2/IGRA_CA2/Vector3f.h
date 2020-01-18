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
};

