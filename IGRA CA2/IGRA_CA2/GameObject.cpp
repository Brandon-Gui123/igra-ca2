#include "GameObject.h"

#include "Component.h"      // for Component class

GameObject::GameObject(){}

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

void GameObject::Draw()
{
	mesh.Draw(position, rotation, scale);
}

void GameObject::Update()
{

}