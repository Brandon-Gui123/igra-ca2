#pragma once

#include "Color4.h"     // for class Color4f

#include "framework.h"  // for the Windows stuff in gl/GL.h file
#include <gl/GL.h>      // for GLfloat and GLubyte

// A compact class that stores 3 values - red, green and blue - to represent colours.
template <typename T>
class Color3
{
public:
    T red;
    T green;
    T blue;

public:
    
    // Constructs a Color3 that is initialized as black (all of its member variables are initialized to 0).
    Color3();

    // Constructs a Color3 with a specified red, blue and green value.
    Color3(T red, T green, T blue);

    // Implicitly converts a Color3 to a Color4. The 4th parameter will be set to 1.0f.
    operator Color4<T>() const;
};

#include "Color3.inl"   // this will be replaced with Color3.inl's contents during compilation
                        // I separated the inline template implemtations from this header file
                        // for clarity and cleanliness purposes

// define common types of Color3<T>

// Color3 with GL floats used as the type for the member fields
using Color3f = Color3<GLfloat>;

// Color3 with GL unsigned bytes used as the type for the member fields
using Color3ub = Color3<GLubyte>;