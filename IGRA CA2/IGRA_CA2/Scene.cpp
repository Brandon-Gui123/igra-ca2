#include "Scene.h"

#include "GameObject.h"

#include <vector>

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

void Scene::Start()
{
	for (std::vector<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it) {
		(*it)->Start();
	}
}

Scene::Scene()
{
}


Scene::~Scene()
{
}
