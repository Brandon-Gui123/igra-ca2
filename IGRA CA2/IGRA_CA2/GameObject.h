#pragma once

#include "Component.h"	// for Component class

#include <vector>		// for std::vector

class Component;

class GameObject
{
private:
	std::vector<Component*> components;

public:
	GameObject();
	~GameObject();

	void AddComponent(Component &co);

	void Draw();
	void Update();
};

