#include "Program.h"

#include "Input.h"			// Input class
#include "GameObject.h"		// GameObject class
#include "PickableMesh.h"	// PickableMesh class
#include "Scene.h"			// Scene class
#include "Vector3f.h"		// Vector3f class

#pragma region Component Includes
#include "Camera.h"
#include "GameManager.h"
#include "Obstacle.h"
#include "Player.h"
#include "TestComponent.h"
#pragma endregion

#pragma region Mesh Includes
#include "LilypadMesh.h"
#include "ObstacleMesh.h"
#include "PlayerMesh.h"
#include "PlankMesh.h"
#pragma endregion

#include "framework.h"		// to define the Windows stuff in gl/GL.h
#include <gl/GL.h>			// OpenGL 32-bit library
#include <gl/GLU.h>			// OpenGL Utilities 32-bit library

#include <iostream>			// std::cout
#include <string>			// std::string, std::to_string
#include <vector>			// std::vector

GLubyte Program::woodTexture[64][64][3];
Program *Program::program;

Program::Program()
{
	Program::program = this;
	score = 0;
	backBufferImage = new GLubyte[initialWindowHeight][initialWindowWidth][3];
}

Program::~Program()
{
	for (Scene *&scenePtr : scenes)
	{
		// deallocate memory occupied by the scene pointer
		// then set it to null pointer to prevent dangling pointers
		delete scenePtr;
		scenePtr = nullptr;
	}

	// clear the vector of scene pointers
	scenes.clear();

	// free up memory occupied by the back buffer image
	delete[] backBufferImage;
	backBufferImage = nullptr;
}

void Program::InitializeScenes()
{
	/////////////////////////////////INIT INPUT/////////////////////////////////
	

	//////////////////////INIT SCENE OBJECTS AND COMPONENTS//////////////////////
	Scene* testScene{new Scene{}};
	scenes.push_back(testScene);

	GameObject* playerGO{new GameObject{"Player", Vector3f::zero, Vector3f{0, 0, 0}, Vector3f::one}};
	GameObject* gameManagerGO{ new GameObject{"GameManager", Vector3f::zero, Vector3f{0, 0, 0}, Vector3f::one} };
	GameObject* cameraGO{ new GameObject{"Camera", Vector3f{10, 10, 10}, Vector3f{0, -135, -40}, Vector3f::one} };
	testScene->gameObjects.push_back(playerGO);
	testScene->gameObjects.push_back(gameManagerGO);
	testScene->gameObjects.push_back(cameraGO);
	playerGO->AddComponent<Player>();
	cameraGO->AddComponent<Camera>();
	PlayerMesh* playerMesh{ new PlayerMesh{} };
	playerGO->mesh = playerMesh;
	LilypadMesh* lilypadMesh{ new LilypadMesh{} };
	PlankMesh* plankMesh{ new PlankMesh{} };
	gameManagerGO->mesh = plankMesh;
	gameManagerGO->AddComponent<GameManager>();


	selectedScene = testScene;
	camera = cameraGO;
}

void Program::DoDestroyCycle()
{
	if (selectedScene->hasGameObjectsToDestroy)
	{
		selectedScene->DoDestroyCycle();
	}
}

void Program::DoStartOnAddedComponents()
{
	selectedScene->MoveNewComponentsToStartVector();
	selectedScene->StartAllNewComponents();
	selectedScene->MoveStartedComponentsToMain();
}

void Program::DoDestroyCycleForPickableMeshes()
{
	std::vector<PickableMesh*>::iterator iterator{PickableMesh::pickableMeshes.begin()};

	while (iterator != PickableMesh::pickableMeshes.end())
	{
		if ((*iterator)->markedForDestruction)
		{
			// to ensure that everything is freed
			(*iterator)->~PickableMesh();
			iterator = PickableMesh::pickableMeshes.erase(iterator);
		}
		else
		{
			++iterator;
		}
	}
}

void Program::MoveNewGOsToMain()
{
	selectedScene->MoveNewToMain();
}

void Program::QueryDeltaTime()
{
	Time::unscaledDeltaTime = Time::internalTimer.GetTimePassedSinceLastTime();
}

void Program::ResetInputKeyUpDownStatus()
{
	Input::ResetKeyDownUp();
}

void Program::ResetMouseButtonUpDownStatus()
{
	Input::ResetMouseButtonDownUp();
}

void Program::StartInternalTimer()
{
	Time::internalTimer.StartTimer();
}

void Program::SendKeyDown(const WPARAM &wParam)
{
	Input::SendKeyDown(wParam);
}

void Program::SendKeyUp(const WPARAM & wParam)
{
	Input::SendKeyUp(wParam);
}

void Program::SendMouseButtonDown(MouseButton mouseButton)
{
	Input::SendMouseButtonDown(mouseButton);
}

void Program::SendMouseButtonUp(MouseButton mouseButton)
{
	Input::SendMouseButtonUp(mouseButton);
}

void Program::SendMousePosition(int x, int y)
{
	Input::windowsMousePosition.Set(x, y);
}

void Program::RestartProgram()
{
	score = 0;

	// clear vector
	PickableMesh::pickableMeshes.clear();

	// clean up everything in all scenes
	for (Scene *&scenePtr : scenes)
	{
		delete scenePtr;
		scenePtr = nullptr;
	}

	// clear vector (which is filled with null pointers)
	scenes.clear();

	// redo init
	InitializeScenes();

	// call Start
	Start();
}

void Program::CreateWoodTexture() {
	int nrOfCheckersOnRow = 8;
	float dim = 64.0 / nrOfCheckersOnRow;
	int red = 0;
	int green = 0;
	int blue = 0;
	for (int i = 0; i < 64; i++) {
		for (int j = 0; j < 64; j++) {

			// Calculate in which checkerboard
			//rectangle the pixel falls
			int row = (int)(i / dim);
			int col = (int)(j / dim);
			int c = 0;
			if (row % 3 == 0) { // Even rows start with black
				if (col % 4 == 0) {
					// All even column will be black
					green = 20;
					blue = 0;
					red = 40;
				}
				else {
					green = 40;
					blue = 0;
					red = 80;
				}
			}
			else {
				// Odd rows start with red
				if (col % 3 == 0) {
					// All even column will be red
					green = 40;
					blue = 0;
					red = 80;
				}
				else {
					green = 30;
					blue = 0;
					red = 60;
				}
			}
			// Drawing a dark brown border around the image
			if (i == 0 || i == 63 || j == 0 || j == 63) {
				red = 60;
				green = 30;
				blue = 0;
			}
			woodTexture[i][j][0] = (GLubyte)red;
			woodTexture[i][j][1] = (GLubyte)green;
			woodTexture[i][j][2] = (GLubyte)blue;
		}
	}
}

void Program::SetupLight() {
	glShadeModel(GL_SMOOTH);
	GLfloat LightAmbient[] = { 0.5, 0.5, 0.5, 1 };
	GLfloat LightDiffuse[] = { 0.5, 0.5, 0.5, 1 };
	GLfloat LightSpecular[] = { 0.5, 0.5, 0.5, 1 };
	GLfloat LightPosition[] = { 10, 10, 10, 0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, LightSpecular);
	glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);
	glEnable(GL_LIGHT0);
}

void Program::DrawPickableMeshes()
{
	if (PickableMesh::pickableMeshes.empty())
	{
		// nothing to draw, so don't bother reading the back buffer
		return;
	}

	for (PickableMesh *&pickableMeshPtr : PickableMesh::pickableMeshes)
	{
		const GameObject &pickableMeshGameObject{pickableMeshPtr->gameObject};

		// draw the pickable mesh at its GameObject's position
		pickableMeshPtr->DrawToBackBuffer(pickableMeshGameObject.position, pickableMeshGameObject.rotation, pickableMeshGameObject.scale);
	}

	// read back buffer to image
	glReadBuffer(GL_BACK);
	glReadPixels(0, 0, initialWindowWidth, initialWindowHeight, GL_RGB, GL_UNSIGNED_BYTE, backBufferImage);

	const Vector2f &mousePosition{Input::GetWindowsMousePosition()};

	const Color4ub colorAtCursor{
		backBufferImage[static_cast<int>(initialWindowHeight - mousePosition.y)][static_cast<int>(mousePosition.x)][0],
		0,
		0,
		1
	};

	// compare the clicked colour with all our other pickable meshes to
	// see which one we select
	for (PickableMesh *&pickableMeshPtr : PickableMesh::pickableMeshes)
	{
		if (colorAtCursor.red == pickableMeshPtr->pickingColor.red)
		{
			pickableMeshPtr->Select();
			return;
		}
	}
}

void Program::Start() {

	// the program starts running after start
	currentPhase = Phase::Running;

	if (selectedScene) selectedScene->Start();
}

void Program::Update() {
	if (selectedScene) selectedScene->Update();
}

void Program::Draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.1f, 0.4f, 1.0f, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// we need to do this because our camera is originally positioned at the origin so we won't see anything
	// position the camera at (1, 1, 1), then look at the origin
	glRotatef(-camera->rotation.z, 1, 0, 0);
	glRotatef(camera->rotation.y + 180, 0, 1, 0);
	glRotatef(camera->rotation.x, 0, 0, 1);
	glTranslatef(camera->position.z, -camera->position.y, -camera->position.x);

	gluLookAt(0, 0, 0,
			  -1, 0, 0,
			  0, 1, 0);

	if (selectedScene) selectedScene->Draw();

	//----------------------------------------------------------------------------------
	//ANYTHING BELOW THIS LINE IS FOR TESTING AND SHOULD BE REMOVED IN THE FINAL PRODUCT
	//----------------------------------------------------------------------------------

	glBegin(GL_LINES);
	// Draw positive x-axis as red
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0, 0, 0);
	glVertex3f(100, 0, 0);
	// Draw positive x-axis as green
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 100, 0);
	// Draw positive z-axis as blue
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 100);

	glEnd();
}

const Program::Phase &Program::GetCurrentPhase()
{
    return currentPhase;
}
