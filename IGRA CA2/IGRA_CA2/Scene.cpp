#include "Scene.h"

#include "GameObject.h"
#include "Program.h"

#include <vector>

Scene::Scene()
{
}


Scene::~Scene()
{
}

void Scene::Start()
{
	for (std::vector<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it) {
		(*it)->Start();
	}
}

void Scene::Update()
{
	for (std::vector<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it) {
		(*it)->Update();
	}
}

void Scene::Draw()
{
	for (std::vector<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it) {
		(*it)->Draw();
	}
}
