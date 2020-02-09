// Done by Ryan Tan (1829105) from DIT/FT/2B/05

#include "Camera.h"

#include "GameObject.h"
#include "Vector3f.h"

void Camera::Update()
{
	gameObject.position = player->gameObject.position + offset;
}

void Camera::Start()
{
	player = GameObject::Find("Player")->GetComponent<Player>();
	offset = Vector3f{ 10, 10, 10 };
}

Camera::Camera(GameObject &go) : Component(go)
{
}

Camera::~Camera()
{
}
