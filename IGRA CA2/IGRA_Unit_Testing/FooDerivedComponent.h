#pragma once

#include "FooComponent.h"
#include "../IGRA_CA2/GameObject.h"     // for GameObject class

class FooDerivedComponent : public FooComponent
{
public:
    FooDerivedComponent(GameObject &go);
    ~FooDerivedComponent();
};

