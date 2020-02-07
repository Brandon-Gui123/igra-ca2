#include "Lily.h"

#include "Vector3f.h"
#include "GameObject.h"
#include "Time.h"

void Lily::Start()
{
	isDropping = false;
	dropTimer = 0.5f;
}

void Lily::Update()
{
	if (isDropping) {
		gameObject.position += Vector3f{ 0,-1,0 } * Time::GetDeltaTime();
		dropTimer -= Time::GetDeltaTime();
		if (dropTimer <= 0) {
			isDropping = false;
			GameObject::Destroy(gameObject);
		}
	}
}

void Lily::Drop() {
	isDropping = true;
}

Lily::Lily(GameObject &go) : Component(go)
{
}


Lily::~Lily()
{
}
