#pragma once

#include <vector>		// for std::vector

// GameObject and Component has a circular dependency between each other 
// where GameObject needs to know Component,
// but Component needs to know about GameObject
// so we include this forward declaration for Component to break this circular dependency
class Component;

class GameObject
{
private:
	std::vector<Component*> components{};

public:
	GameObject();
	~GameObject();

	// Returns the number of components attached to this GameObject.
	int GetComponentCount();

	// Adds the component of type T to this GameObject. T must be a type derived from the Component class.
	template <typename T>
	T& AddComponent();

	// Gets the first occurence of a component of type T from this GameObject. T must be a type derived from the Component class.
	template <typename T>
	T* GetComponent();

	void Draw();
	void Update();
};

template<typename T>
inline T& GameObject::AddComponent()
{
	T* instance{new T{*this}};
	components.push_back(instance);
	return *instance;
}
