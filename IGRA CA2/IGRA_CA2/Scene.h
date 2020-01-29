#pragma once

#include "GameObject.h"

#include <vector>

class Scene
{
public:
	std::vector<GameObject*> gameObjects;

	Scene();
	~Scene();

	void Start();
	void Update();
	void Draw();
};

