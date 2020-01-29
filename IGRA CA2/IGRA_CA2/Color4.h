#pragma once

#include "framework.h"  // for the Windows stuff in gl/GL.h file
#include <gl/GL.h>      // for GLfloat and GLubyte

// A compact class that stores 4 values - red, green, blue and alpha - to represent colours and transparency.
template <typename T>
class Color4
{

public:
    T red;
    T green;
    T blue;
    T alpha;

    // Constructs a Color4 that is initialized as black (all of its member variables are initialized to 0).
    Color4();

    // Constructs a Color4 with the specified values.
    Color4(float red, float green, float blue, float alpha);
};

template<typename T>
inline Color4<T>::Color4() : red{0}, green{0}, blue{0}, alpha{0}
{}

template<typename T>
inline Color4<T>::Color4(float red, float green, float blue, float alpha) : red{red}, green{green}, blue{blue}, alpha{alpha}
{}

// define most common types of Color4

// Color4 with GL floats as the type for its member fields
using Color4f = Color4<GLfloat>;

// Color4 with GL unsigned bytes as the type for its member fields
using Color4ub = Color4<GLubyte>;