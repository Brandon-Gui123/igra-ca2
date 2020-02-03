#pragma once
#include "Component.h"
class GameManager : public Component
{
public:
	void Update() override;
	void Start() override;
	GameManager(GameObject &go);
	~GameManager();
};

