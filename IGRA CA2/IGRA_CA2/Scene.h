#pragma once

#include "GameObject.h"

#include <vector>

class Scene
{
private:
	std::vector<GameObject*> gameObjects;

public:

	Scene();
	virtual ~Scene();

	void Start();
	void Update();
	void Draw();
};

