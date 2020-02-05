#pragma once

#include "Component.h"
#include "Vector3f.h"
#include "GameManager.h"

class Player : public Component
{
private:
	bool isJumping;
	float jumpTimer;
	void JumpStart(bool left);
	void Jump();
	Vector3f PrevPos;
	Vector3f direction;
	GameManager * gameManager;

public:
	void Update() override;
	void Start() override;

	float speed = 3.0f;

	Player(GameObject &go);
	~Player();
};

