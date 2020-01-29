#pragma once

#include "Component.h"

class Player : public Component
{
public:
	void Update() override;
	void Start() override;
	Player(GameObject &go);
	~Player();
};

