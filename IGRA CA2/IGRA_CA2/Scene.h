// Done by Brandon Gui (1828865) and Ryan Tan (1829105) from DIT/FT/2B/05

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

	// To allow the Program class to call component-handling methods (e.g. MoveStartedComponentsToMain()).
	friend class Program;

	// To allow the GameObject class to access the GameObjects in the currently selected scene.
	friend class GameObject;
};

