#pragma once

#include "../IGRA_CA2/Component.h"      // base class for all Components (Component in IGRA CA2)
#include "../IGRA_CA2/GameObject.h"     // for class GameObject in IGRA CA2

class TestComponent : public Component
{
public:
    TestComponent(GameObject &go);
    ~TestComponent();
};

