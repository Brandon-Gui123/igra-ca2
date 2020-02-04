#include "GameObject.h"

#include "Component.h"      // for Component class
#include "Program.h"		// for Program class
#include "Scene.h"			// for Scene class

#include <vector>			// for std::vector
#include <string>			// for std::string.compare

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

GameObject::GameObject(std::string n) : name(n){
	Vector3f sca(1.0f, 1.0f, 1.0f); //Scale Defaults at 1 per axis
	scale = sca;
}

GameObject::GameObject(std::string n, const Vector3f& pos, const Vector3f& rot, const Vector3f& sca)
	: name(n), position(pos), rotation(rot), scale(sca){}

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
	mesh->Draw(position, rotation, scale);
}

void GameObject::OnMeshSelected()
{
    for (std::vector<Component*>::iterator it = components.begin(); it != components.end(); ++it)
    {
        (*it)->OnGameObjectSelected();
    }
}
