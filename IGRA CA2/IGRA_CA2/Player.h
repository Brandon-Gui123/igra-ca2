#pragma once

#include "Component.h"

class Player : public Component
{
public:
	void Update() override;
	void Start() override;

	float speed = 3.0f;

	Player(GameObject &go);
	~Player();
};

