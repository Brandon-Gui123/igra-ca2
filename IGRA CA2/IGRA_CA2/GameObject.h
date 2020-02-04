#pragma once

#include "Component.h"	// for class Component (resolve complete class type errors)
#include "Mesh.h"		// for class Mesh, which allows displaying the GameObject with shapes
#include "Scene.h"		// for friending Scene class
#include "Vector3f.h"	// for class Vector3f, which allows storing positions, rotations and scaling

#include <vector>		// for std::vector
#include <string>		// for std::string.compare

// GameObject and Component has a circular dependency between each other 
// where GameObject needs to know Component,
// but Component needs to know about GameObject
// so we include this forward declaration for Component to break this circular dependency
class Component;

class GameObject
{
private:
	std::vector<Component*> components{};
	bool markedForDestruction{false};

public:
	// Marks the GameObject for destruction, where the GameObject is
	// destroyed after the current Update loop.
	static void Destroy(GameObject &gameObject);

	// Gets the first occurence of the GameObject with the specifc name.
	// If none are found, a null pointer is returned.
	static GameObject* Find(std::string n);

	// Creates a GameObject with the given name, placed at the specified position
	// with the specified rotation and scale.
	// The created GameObject will be placed in the scene automatically for you.
	static GameObject& Create(const std::string &name, const Vector3f &position, const Vector3f &rotation, const Vector3f &scale);

	std::string name;

	// Stores the Position of the Object
	Vector3f position;
	Vector3f rotation;
	Vector3f scale;

	// Stores the Mesh data of the Object
	Mesh *mesh;

	GameObject(std::string n);
	GameObject(std::string n, const Vector3f &pos, const Vector3f &rot, const Vector3f &sca);
	~GameObject();

	// Returns the number of components attached to this GameObject.
	int GetComponentCount();

	// Adds the component of type T to this GameObject. T must be a type derived from the Component class.
	template <typename T>
	T& AddComponent();

	// Gets the first occurence of a component of type T from this GameObject. T must be a type derived from the Component class.
	template <typename T>
	T* GetComponent();

	void Start();
	void Update();
	void Draw();

	void OnMeshSelected();

	friend class Scene;
};

template<typename T>
inline T& GameObject::AddComponent()
{
	T* instance{new T{*this}};
	components.push_back(instance);
	return *instance;
}

template<typename T>
inline T* GameObject::GetComponent()
{
	for (Component *&component : components)
	{
		// attempt to downcast from Component to type T (casting to a more specific type)
		// if the downcast is successful, we will get the component as type T
		// if the downcast fails, we will get a null pointer to type T
		T* instance{dynamic_cast<T*>(component)};

		if (instance != nullptr)
		{
			// we already found the component, so return it
			return instance;
		}
	}

	// if we managed to reach here, it means we've found nothing
	// so we return a null pointer
	return nullptr;
}
