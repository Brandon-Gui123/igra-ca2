#pragma once

#include "Component.h"
#include "Vector3f.h"

class Lily : public Component
{
private:
	bool isDropping;
	float dropTimer;

	int easyScore{50};
	int normalScore{100};
	int hardScore{150};

public:
	bool isGoal{false};
	bool hasObstacle{false};

	int GetAwardedScore();

	void Start() override;
	void Update() override;
	void Drop();
	Lily(GameObject &go);
	~Lily();
};

