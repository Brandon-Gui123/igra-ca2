#pragma once
#include "Component.h"

#include <vector>

class GameManager : public Component
{
private:
	std::vector<GameObject*> lilyPads;
	std::vector<int> map;
public:
	void Update() override;
	void Start() override;
	GameManager(GameObject &go);
	~GameManager();
};

