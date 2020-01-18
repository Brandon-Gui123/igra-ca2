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
};
