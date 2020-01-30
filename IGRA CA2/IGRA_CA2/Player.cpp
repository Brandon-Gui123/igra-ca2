#include "Player.h"

#include "Vector3f.h"
#include "Input.h"
#include "Time.h"

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
		left++;
	}

	if (Input::GetKey(KeyCode::D)) {
		left--;
	}

	if (Input::GetKey(KeyCode::W)) {
		up++;
	}

	if (Input::GetKey(KeyCode::S)) {
		up--;
	}

	Vector3f delta(left * Time::GetDeltaTime(), 0, up * Time::GetDeltaTime());
	Vector3f newPos = delta + gameObject.position;
	gameObject.position = newPos;
}
