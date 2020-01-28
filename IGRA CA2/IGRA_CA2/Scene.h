#pragma once

#include "GameObject.h"

#include <vector>

class Scene
{
public:
	std::vector<GameObject*> gameObjects;
	void Draw();
	void Update();
	void Start();

	Scene();
	~Scene();
};

