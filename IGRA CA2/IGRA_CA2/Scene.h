#pragma once

#include <vector>
#include "GameObject.h"
class Scene
{
public:
	std::vector<GameObject> gameObjects;
	void Draw();
	void Update();

	Scene();
	~Scene();
};

