#include "GameObject.h"

#include "Component.h"      // for Component class

#include <vector>

GameObject::GameObject(){
	Vector3f sca(1.0f, 1.0f, 1.0f); //Scale Defaults at 1 per axis
	scale = sca;
}

GameObject::GameObject(const Vector3f& pos, const Vector3f& rot, const Vector3f& sca) 
	: position(pos), rotation(rot), scale(sca){}

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
	mesh.Draw(position, rotation, scale);
}