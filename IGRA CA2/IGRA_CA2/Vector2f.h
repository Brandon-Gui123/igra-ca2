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
};

