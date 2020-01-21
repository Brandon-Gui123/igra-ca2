#pragma once
#include "Component.h"
#include <vector>
class GameObject
{
public:
	std::vector<Component> components;
	void Draw();
	void Update();
	GameObject();
	~GameObject();
};

