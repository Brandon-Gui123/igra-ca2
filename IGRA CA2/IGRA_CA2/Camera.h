#pragma once

#include "Component.h"
#include "GameObject.h"
#include "Player.h"
#include "Vector3f.h"

class Camera : public Component
{
private:
	Player * player;
	Vector3f offset;
public:
	void Update() override;
	void Start() override;
	Camera(GameObject &go);
	~Camera();
};

