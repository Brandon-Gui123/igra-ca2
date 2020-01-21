#include "Scene.h"

#include <vector>
#include "GameObject.h"


void Scene::Draw()
{
	for (std::vector<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it) {
		(*it)->Draw();
	}
}

void Scene::Update()
{
	for (std::vector<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it) {
		(*it)->Update();
	}
}

Scene::Scene()
{
}


Scene::~Scene()
{
}
