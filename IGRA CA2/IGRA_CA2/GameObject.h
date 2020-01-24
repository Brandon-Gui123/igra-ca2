#pragma once
#include "Component.h"
#include <vector>
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

