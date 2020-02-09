// This file is used in a unit testing project which tests the classes and ensures that
// everything runs as intended.
//
// Done by Brandon Gui (p1828865) from DIT/FT/2B/05.

#pragma once

#include "FooComponent.h"
#include "../IGRA_CA2/GameObject.h"     // for GameObject class

class FooDerivedComponent : public FooComponent
{
public:
    FooDerivedComponent(GameObject &go);
    ~FooDerivedComponent();
};

