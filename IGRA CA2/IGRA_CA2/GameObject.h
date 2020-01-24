#pragma once
#include "Component.h"
#include <vector>
class Component;

class GameObject
{
private:
	std::vector<Component*> components;

public:
	void Draw();
	void Update();
	void AddComponent(Component &co);
	GameObject();
	~GameObject();
};

