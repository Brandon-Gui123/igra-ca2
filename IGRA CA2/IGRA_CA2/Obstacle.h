#pragma once

#include "Component.h"  // for base class Component
#include "GameObject.h" // for class GameObject
#include "Lily.h"       // for Lily component

class Obstacle : public Component
{
public:
    Obstacle(GameObject &gameObject);
    ~Obstacle();

    Lily *lily; // The lily that this obstacle is on.

    // Called when the mesh of the GameObject is selected.
	void OnGameObjectSelected() override;
};
