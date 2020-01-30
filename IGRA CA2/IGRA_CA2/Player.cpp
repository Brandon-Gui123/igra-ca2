#include "Player.h"

#include "Vector3f.h"
#include "Input.h"
#include "Time.h"
#include "GameObject.h"
#include "Math.h"

Player::Player(GameObject &go) : Component(go)
{
}

Player::~Player()
{
}

void Player::Start()
{
}

void Player::Update()
{
	float up = 0;
	float left = 0;

	if (Input::GetKey(KeyCode::A)) {
		left += sin(45);
		up -= sin(45);
	}

	if (Input::GetKey(KeyCode::D)) {
		left -= sin(45);
		up += sin(45);
	}

	if (Input::GetKey(KeyCode::W)) {
		left += sin(45);
		up += sin(45);
	}

	if (Input::GetKey(KeyCode::S)) {
		left -= sin(45);
		up -= sin(45);
	}

	Vector3f delta(left * Time::GetDeltaTime() * speed, 0, up * Time::GetDeltaTime() * speed);
	Vector3f newPos = delta + gameObject.position;
	gameObject.position = newPos;
}
