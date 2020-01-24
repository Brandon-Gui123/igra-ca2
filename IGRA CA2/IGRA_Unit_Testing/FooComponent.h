#pragma once

#include "../IGRA_CA2/Component.h"      // for base class Component in IGRA CA2 project
#include "../IGRA_CA2/GameObject.h"     // for class GameObject in IGRA CA2 project

class FooComponent : public Component
{
public:
    FooComponent(GameObject &go);
    ~FooComponent();
};

