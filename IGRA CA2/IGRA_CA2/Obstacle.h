#pragma once

#include "Component.h"  // for base class Component
#include "GameObject.h" // for class GameObject

class Obstacle : public Component
{
public:
    Obstacle(GameObject &gameObject);
};
