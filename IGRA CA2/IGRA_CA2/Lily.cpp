#include "Lily.h"

#include "GameDifficulty.h"
#include "Vector3f.h"
#include "GameObject.h"
#include "Time.h"

int Lily::GetAwardedScore()
{
	switch (Program::program->currentDifficulty)
	{
		case GameDifficulty::Easy:
			return easyScore;

		case GameDifficulty::Normal:
			return normalScore;

		case GameDifficulty::Hard:
			return hardScore;

		default:
			// unknown difficulty
			return 0;
	}
}

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
	Program::program->score += GetAwardedScore();
	isDropping = true;
}

Lily::Lily(GameObject &go) : Component(go)
{
}


Lily::~Lily()
{
}
