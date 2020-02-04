#pragma once

#include "GameObject.h"

#include <vector>

// To break circular dependency between Scene and Program
class Program;

class Scene
{
private:
	std::vector<GameObject*> gameObjects;
	bool hasGameObjectsToDestroy{false};

public:

	Scene();
	virtual ~Scene();

	void Start();
	void Update();
	void Draw();
	void DoDestroyCycle();

	friend class Program;
	friend class GameObject;
};

