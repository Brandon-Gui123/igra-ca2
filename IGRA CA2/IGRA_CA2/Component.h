#pragma once

// GameObject and Component has a circular dependency between each other 
// where GameObject needs to know Component,
// but Component needs to know about GameObject
// so we include this forward declaration for GameObject to break this circular dependency
class GameObject;

class Component
{
public:
	GameObject &gameObject;

	Component(GameObject &go);
	virtual ~Component();

	virtual void Start();
	virtual void Update();
	virtual void OnGameObjectSelected();
};