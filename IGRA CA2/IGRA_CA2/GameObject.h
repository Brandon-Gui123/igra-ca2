#pragma once

#include "Component.h"	// for class Component (resolve complete class type errors)
#include "Mesh.h"		// for class Mesh, which allows displaying the GameObject with shapes
#include "Program.h"	// for accessing Program's current phase
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

	// We're using 2 vectors to deal with newly-added components
	// so that we can handle the case where new components are added during
	// Start, which will interfere with iterating the vector since adding
	// new components to it will invalidate all iterators.
	std::vector<Component*> newlyAddedComponents{};
	std::vector<Component*> componentsToStart{};

	bool markedForDestruction{false};

	// Moves the newly-added components from its vector to the
	// vector of components whose Start must be called.
	void MoveNewComponentsToStartVector();

	// Moves the components from the Start vector to the main vector.
	void MoveStartedComponentsToMain();

	// Calls the Start method in all components in the start vector.
	void ExecuteComponentsInStartVector();

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

	// A string representation of this GameObject.
	// This gives the GameObject an identity, but does not exactly identify it.
	// For instance, a GameObject can be identified by this name, but the GameObject identified
	// may not exactly be this GameObject.
	std::string name;

	Vector3f position;	// The current position of the GameObject relative to the world.
	Vector3f rotation;	// The current rotation of the GameObject relative to the world.
	Vector3f scale;		// The current scale of the GameObject relative to the world.

	// The pointer to the mesh of the GameObject, which determines what this GameObject will show.
	Mesh *mesh{nullptr};

	// Constructs a new GameObject with the specified name and the default position, rotation and scaling values.
	GameObject(const std::string &name);

	// Constructs a new GameObject with the specified name, position, rotation and scaling.
	GameObject(const std::string &name, const Vector3f &position, const Vector3f &rotation, const Vector3f &scale);

	// Frees up memory occupied by the GameObject's components and mesh.
	// You can no longer use the components and meshes after this is done.
	~GameObject();

	// Returns the number of components attached to this GameObject.
	int GetComponentCount();

	// Adds the component of type T to this GameObject. T must be a type derived from the Component class.
	template <typename T>
	T& AddComponent();

	// Gets the first occurence of a component of type T from this GameObject. T must be a type derived from the Component class.
	template <typename T>
	T* GetComponent();

#pragma region Messages

	// Called once for each GameObject after all GameObjects and its components are loaded.
	// This is also called after the end of the Draw loop for all GameObjects created during the
	// Update loop.
	void Start();

	// Called once per frame. This will call Update on all components attached to this GameObject.
	void Update();

	// Called once per frame. This will draw the mesh on this GameObject, if it has one.
	void Draw();

	// Called when the mesh of this GameObject is selected by the mouse cursor.
	void OnMeshSelected();

#pragma endregion

	friend class Scene;
};

#include "GameObject.inl"	// will be replaced by the contents in the GameObject.inl file
							// template implementation is separated and placed in this folder
							// for readability