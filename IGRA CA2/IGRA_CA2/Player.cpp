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
	Vector3f delta(Input::GetAxis(Input::x), 0, Input::GetAxis(Input::y));
	Vector3f newPos = delta * speed * Time::GetDeltaTime() + gameObject.position;
	gameObject.position = newPos;
}
