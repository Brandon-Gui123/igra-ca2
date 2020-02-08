#pragma once

#include "Component.h"
#include "Vector3f.h"
#include "GameManager.h"

class GameManager;

class Player : public Component
{
private:
	bool isJumping;
	bool dead;
	bool isDropping;
	float jumpTimer;
	float dropTimer;
	void JumpStart(bool left);
	void Jump();
	Vector3f PrevPos;
	Vector3f direction;
	GameManager * gameManager;

public:
	void Update() override;
	void Start() override;
	void Die();

	float speed = 3.0f;

	Player(GameObject &go);
	~Player();
};

