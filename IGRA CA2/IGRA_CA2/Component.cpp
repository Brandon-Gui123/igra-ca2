#include "Component.h"

#include "GameObject.h"

Component::Component(GameObject &go): gameObject(go)
{
	gameObject.AddComponent(*this);
}

Component::~Component()
{

}
