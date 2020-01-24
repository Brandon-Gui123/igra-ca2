#pragma once

#include "Component.h"	// for Component class

#include <vector>		// for std::vector

// GameObject and Component has a circular dependency between each other 
// where GameObject needs to know Component,
// but Component needs to know about GameObject
// so we include this forward declaration for Component to break this circular dependency
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

