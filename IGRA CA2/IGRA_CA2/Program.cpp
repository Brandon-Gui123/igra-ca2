#include "Program.h"

#include "GameObject.h"
#include "Input.h"			// for Input class
#include "TestComponent.h"
#include "Vector3f.h"

#include "framework.h"
#include <gl/GL.h>  // OpenGL 32-bit library
#include <gl/GLU.h> // OpenGL Utilities 32-bit library

#include <iostream>   // std::cout
#include <string>     // std::string, std::to_string
#include <vector>

Scene testScene;
GameObject testGo;

Program::Program()
{}

Program::~Program()
{}

void Program::QueryDeltaTime()
{
	Time::deltaTime = Time::internalTimer.GetTimePassedSinceLastTime();
}

void Program::ResetInputKeyUpDownStatus()
{
	Input::ResetKeyDownUp();
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


	//----------------------------------------------------------------------------------
	//ANYTHING BELOW THIS LINE IS FOR TESTING AND SHOULD BE REMOVED IN THE FINAL PRODUCT
	//----------------------------------------------------------------------------------
	testScene.gameObjects.push_back(&testGo);
	Vector3f rot(0, 45, 0);
	testGo.rotation = rot;
	testGo.AddComponent<TestComponent>();
	selectedScene = &testScene;
}

void Program::Start() {
	if (selectedScene) selectedScene->Start();
}

void Program::Update() {
	if (selectedScene) selectedScene->Update();
}

void Program::Draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.5f, 0.f, 0.8f, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// we need to do this because our camera is originally positioned at the origin so we won't see anything
	// position the camera at (1, 1, 1), then look at the origin
	gluLookAt(
		10, 10, 10, // Camera's position (we move the camera further down the z-axis to see our cube)
		0, 0, 0,    // Camera's target to look at
		0, 1, 0     // Orientation of the camera
	);

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
