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

	// Tells all GameObjects in the scene to move newly-added components to the vector
	// where all components in there have their Start method called
	void MoveNewComponentsToStartVector();

	// Tells all GameObjects in the scene to Start all components in the start vector
	void StartAllNewComponents();

	// Tells all GameObjects in the scene to move all components in the start vector
	// to the main vector.
	void MoveStartedComponentsToMain();

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

