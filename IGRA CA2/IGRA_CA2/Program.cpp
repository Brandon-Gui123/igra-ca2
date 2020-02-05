#include "Program.h"

#include "GameObject.h"
#include "Input.h"			// for Input class
#include "Scene.h"
#include "TestComponent.h"
#include "Player.h"
#include "PlayerMesh.h"
#include "LilypadMesh.h"
#include "Vector3f.h"
#include "GameManager.h"

#include "framework.h"
#include <gl/GL.h>  // OpenGL 32-bit library
#include <gl/GLU.h> // OpenGL Utilities 32-bit library

#include <iostream>   // std::cout
#include <string>     // std::string, std::to_string
#include <vector>

GLubyte Program::placeholderTexture[64][64][3];
Program *Program::program;

Program::Program()
{
	Program::program = this;
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
}

void Program::InitializeScenes()
{
	/////////////////////////////////INIT INPUT/////////////////////////////////


	//////////////////////INIT SCENE OBJECTS AND COMPONENTS//////////////////////
	Scene* testScene{new Scene{}};
	scenes.push_back(testScene);

	GameObject* playerGO{new GameObject{"Player", Vector3f::zero, Vector3f{0, 0, 0}, Vector3f::one}};
	GameObject* gameManagerGO{ new GameObject{"GameManager", Vector3f::zero, Vector3f{0, 0, 0}, Vector3f::one} };
	GameObject* cameraGO{ new GameObject{"Camera", Vector3f{10, 10, 10}, Vector3f{0, -135, -45}, Vector3f::one} };
	testScene->gameObjects.push_back(playerGO);
	testScene->gameObjects.push_back(gameManagerGO);
	testScene->gameObjects.push_back(cameraGO);
	playerGO->AddComponent<Player>();
	PlayerMesh* playerMesh{ new PlayerMesh{} };
	playerGO->mesh = playerMesh;
	LilypadMesh* lilypadMesh{ new LilypadMesh{} };
	gameManagerGO->mesh = lilypadMesh;
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

void Program::CreateCheckerBoardTexture() {
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
			if (row % 2 == 0) { // Even rows start with black
				if (col % 2 == 0) {
					// All even column will be black
					red = green = blue = 0;
				}
				else {
					green = 100;
					blue = 0;
					red = 255;
				}
			}
			else {
				// Odd rows start with red
				if (col % 2 == 0) {
					// All even column will be red
					green = 100;
					blue = 0;
					red = 255;
				}
				else {
					red = green = blue = 0;
				}
			}
			// Drawing a green border around the image
			if (i == 0 || i == 63 || j == 0 || j == 63) {
				red = 0;
				green = 255;
				blue = 0;
			}
			placeholderTexture[i][j][0] = (GLubyte)red;
			placeholderTexture[i][j][1] = (GLubyte)green;
			placeholderTexture[i][j][2] = (GLubyte)blue;
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
