#pragma once

// GameObject and Component has a circular dependency between each other 
// where GameObject needs to know Component,
// but Component needs to know about GameObject
// so we include this forward declaration for GameObject to break this circular dependency
class GameObject;

class Component
{
public:
	
	// The GameObject that this component is attached to.
	GameObject &gameObject;

	Component(GameObject &go);
	virtual ~Component();

	/// Messages ///

	// Called once when the component is created and after the last frame finishes.
	virtual void Start();

	// Called on every frame.
	virtual void Update();

	// Called when the mesh of the GameObject is selected.
	virtual void OnGameObjectSelected();
};