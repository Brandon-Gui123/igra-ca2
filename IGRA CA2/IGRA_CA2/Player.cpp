#include "Player.h"

#include "Vector3f.h"
#include "Input.h"
#include "Time.h"
#include "GameObject.h"
#include "Math.h"
#include "GameManager.h"

Player::Player(GameObject &go) : Component(go)
{
	isJumping = false;
	jumpTimer = 0;
}

Player::~Player()
{
}

void Player::Start()
{
	gameManager = GameObject::Find("GameManager")->GetComponent<GameManager>();
	dead = false;
}

void Player::Die()
{
	dead = true;
}

void Player::JumpStart(bool left) {
	if (!isJumping) {
		PrevPos = gameObject.position;
		if (left) {
			direction = { *new Vector3f(0, 0, 2) };
			gameObject.rotation = { *new Vector3f(0, 0, 0) };
		}
		else {
			direction = { *new Vector3f(2, 0, 0) };
			gameObject.rotation = { *new Vector3f(0, 90, 0) };
		}
		isJumping = true;
	}
}

void Player::Jump() {
	if (jumpTimer < 1) {
		float y = -4 * std::pow(jumpTimer, 2) + 4 * jumpTimer;
		float m = jumpTimer;
		Vector3f mv = m * direction;
		Vector3f delta(0, y, 0);
		delta += mv;
		gameObject.position = PrevPos + delta;
		jumpTimer += Time::GetDeltaTime() * 3;
	}
	else {
		isJumping = false;
		jumpTimer = 0;
		gameObject.position = PrevPos + direction;
		gameObject.position.y = 0;
		bool left;
		if (direction.x != 0) {
			left = false;
		} else{
			left = true;
		}
		gameManager->PlayerLand(left);
	}
}

void Player::Update()
{
	if (!dead) {
		if (isJumping) {
			Jump();
		}

		if (Input::GetKeyDown(KeyCode::A)) {
			JumpStart(true);
		}

		if (Input::GetKeyDown(KeyCode::D)) {
			JumpStart(false);
		}
	}
	/*Vector3f delta(Input::GetAxis(Input::x), 0, Input::GetAxis(Input::y));
	Vector3f newPos = delta.GetNormalized() * speed * Time::GetDeltaTime() + gameObject.position;
	gameObject.position = newPos;*/
}
