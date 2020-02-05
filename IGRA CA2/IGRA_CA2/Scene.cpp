#include "Scene.h"

#include "GameObject.h"
#include "Program.h"

#include <vector>

Scene::Scene()
{
}


Scene::~Scene()
{
	for (GameObject *&gameObjectPtr : gameObjects)
	{
		// deallocate memory occupied by the object pointed to by the pointer
		// then set the pointer to null pointer to prevent dangling pointers
		delete gameObjectPtr;
		gameObjectPtr = nullptr;
	}

	// clear the vector of null pointers
	gameObjects.clear();
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

void Scene::DoDestroyCycle()
{
	std::vector<GameObject*>::iterator iterator{gameObjects.begin()};

	while (iterator != gameObjects.end())
	{
		if ((*iterator)->markedForDestruction)
		{
			// to ensure that all components are freed of its memory
			(*iterator)->~GameObject();
			iterator = gameObjects.erase(iterator);
		}
		else
		{
			++iterator;
		}
	}
}

void Scene::MoveNewToMain()
{
	for (GameObject *&goPtr : newlyAddedGameObjects)
	{
		gameObjects.push_back(goPtr);
	}

	newlyAddedGameObjects.clear();
}

void Scene::MoveNewComponentsToStartVector()
{
	for (GameObject *&gameObjectPtr : gameObjects)
	{
		gameObjectPtr->MoveNewComponentsToStartVector();
	}
}

void Scene::StartAllNewComponents()
{
	for (GameObject *&gameObjectPtr : gameObjects)
	{
		gameObjectPtr->ExecuteComponentsInStartVector();
	}
}

