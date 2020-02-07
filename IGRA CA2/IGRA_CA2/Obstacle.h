#pragma once

#include "Component.h"  // for base class Component
#include "GameObject.h" // for class GameObject

class Obstacle : public Component
{
public:
    Obstacle(GameObject &gameObject);
    ~Obstacle();

    // Called when the mesh of the GameObject is selected.
	void OnGameObjectSelected() override;
};
