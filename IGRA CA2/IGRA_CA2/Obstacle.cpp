#include "Obstacle.h"

#include "GameDifficulty.h" // for GameDifficulty enum class
#include "GameObject.h" // for class GameObject
#include "Program.h"    // for class Program

Obstacle::Obstacle(GameObject &gameObject) : Component{gameObject}
{}

Obstacle::~Obstacle()
{}

float Obstacle::GetSpawnChance()
{
    switch (Program::program->currentDifficulty)
    {
        case GameDifficulty::Easy:
            return easySpawnChance;

        case GameDifficulty::Normal:
            return normalSpawnChance;

        case GameDifficulty::Hard:
            return hardSpawnChance;

        default:
            // unknown difficulty
            return 0.0f;
    }
}

void Obstacle::OnGameObjectSelected()
{
    GameObject::Destroy(gameObject);
    
    if (lily)
        lily->hasObstacle = false;
}
