#include "Obstacle.h"

#include "GameObject.h" // for class GameObject

Obstacle::Obstacle(GameObject &gameObject) : Component{gameObject}
{}

Obstacle::~Obstacle()
{}

void Obstacle::OnGameObjectSelected()
{
    GameObject::Destroy(gameObject);
}
