// Done by Brandon Gui (1828865) from DIT/FT/2B/05

#pragma once

#include "Component.h"  // for base class Component
#include "GameObject.h" // for class GameObject
#include "Lily.h"       // for Lily component

class Obstacle : public Component
{
private:

    static constexpr float easySpawnChance{0.2f};
    static constexpr float normalSpawnChance{0.4f};
    static constexpr float hardSpawnChance{0.7f};

public:
    Obstacle(GameObject &gameObject);
    ~Obstacle();

    Lily *lily; // The lily that this obstacle is on.

    static float GetSpawnChance();

    // Called when the mesh of the GameObject is selected.
	void OnGameObjectSelected() override;
};
