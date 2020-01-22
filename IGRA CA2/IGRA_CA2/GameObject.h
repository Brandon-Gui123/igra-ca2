#pragma once
#include "Component.h"
#include <vector>
class Component;

class GameObject
{
public:
	std::vector<Component*> components;
	void Draw();
	void Update();
	void AddComponent(Component &co);
	GameObject();
	~GameObject();
};

