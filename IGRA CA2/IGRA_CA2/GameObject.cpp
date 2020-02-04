#include "GameObject.h"

#include "Component.h"      // for Component class
#include "Program.h"		// for Program class
#include "Scene.h"			// for Scene class

#include <vector>			// for std::vector
#include <string>			// for std::string.compare

void GameObject::MoveNewComponentsToStartVector()
{
	for (Component *&comp : newlyAddedComponents)
	{
		componentsToStart.push_back(comp);
	}

	// so that existing components inside aren't considered
	// new as their Start methods are going to be executed
	newlyAddedComponents.clear();
}

void GameObject::ExecuteComponentsInStartVector()
{
	for (Component *&comp : componentsToStart)
	{
		comp->Start();
	}
}

void GameObject::Destroy(GameObject &gameObject)
{
	Program::program->selectedScene->hasGameObjectsToDestroy = true;
	gameObject.markedForDestruction = true;
}

GameObject* GameObject::Find(std::string n)
{
	std::vector<GameObject*> &gos = Program::program->selectedScene->gameObjects;
	for (std::vector<GameObject*>::iterator it = gos.begin(); it != gos.end(); ++it) {
		if (n.compare((*it)->name)) {
			return (*it);
		}
	}
	return nullptr;
}

GameObject& GameObject::Create(const std::string &name, const Vector3f &position, const Vector3f &rotation, const Vector3f &scale)
{
	GameObject *instance{new GameObject{name, position, rotation, scale}};
	Program::program->selectedScene->newlyAddedGameObjects.push_back(instance);
	return *instance;
}

GameObject::GameObject(const std::string &name) : name{name}, position{Vector3f::zero}, rotation{Vector3f::zero}, scale{Vector3f::one}
{}

GameObject::GameObject(const std::string &name, const Vector3f &position, const Vector3f &rotation, const Vector3f &scale)
	: name(name), position(position), rotation(rotation), scale(scale)
{}

GameObject::~GameObject()
{
    for (Component *&comp : components)
    {
        // free memory occupied by the components
        // then set it to a null pointer to prevent undefined behaviour due to
        // dereferencing freed memory
        delete comp;
        comp = nullptr;
    }

    // clear the vector, which contains null pointers
    components.clear();

	// free up memory occupied by the mesh
	delete mesh;
	mesh = nullptr;
}

int GameObject::GetComponentCount()
{
    return components.size();
}

void GameObject::Start() {
	for (std::vector<Component*>::iterator it = components.begin(); it != components.end(); ++it) {
		(*it)->Start();
	}
}

void GameObject::Update()
{
	for (std::vector<Component*>::iterator it = components.begin(); it != components.end(); ++it) {
		(*it)->Update();
	}
}

void GameObject::Draw()
{
	if (mesh != nullptr)
	{
		mesh->Draw(position, rotation, scale);
	}
}

void GameObject::OnMeshSelected()
{
    for (std::vector<Component*>::iterator it = components.begin(); it != components.end(); ++it)
    {
        (*it)->OnGameObjectSelected();
    }
}
