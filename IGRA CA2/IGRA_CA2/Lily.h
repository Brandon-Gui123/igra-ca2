#pragma once

#include "Component.h"
#include "Vector3f.h"

class Lily : public Component
{
private:
	bool isDropping;
	float dropTimer;
public:
	bool isGoal{false};
	bool hasObstacle{false};
	void Start() override;
	void Update() override;
	void Drop();
	Lily(GameObject &go);
	~Lily();
};

