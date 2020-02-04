#pragma once

#include "GameObject.h"

#include <vector>

// To break circular dependency between Scene and Program
class Program;

class Scene
{
private:
	std::vector<GameObject*> gameObjects;
	std::vector<GameObject*> newlyAddedGameObjects;

	bool hasGameObjectsToDestroy{false};

	// Moves the newly-added GameObjects to the standard GameObjects vector.
	void MoveNewToMain();

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

