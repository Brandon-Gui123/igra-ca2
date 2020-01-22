#pragma once
#include "GameObject.h"
class GameObject;

class Component
{
public:
	GameObject &gameObject;
	Component();
	~Component();
};