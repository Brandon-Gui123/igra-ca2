#include "Program.h"
#include "framework.h"

#include <gl/GL.h>  // OpenGL 32-bit library
#include <gl/GLU.h> // OpenGL Utilities 32-bit library


#include <iostream>   // std::cout
#include <string>     // std::string, std::to_string
#include <vector>

void Program::StartInternalTimer()
{
	Time::internalTimer.StartTimer();
}

void Program::QueryDeltaTime()
{
	Time::deltaTime = Time::internalTimer.GetTimePassedSinceLastTime();
}

Program::Program()
{
}

void Program::Update() {
	if (selectedScene) selectedScene->Update();
}

float cubeVertices[][3] = {
{ -1.0f, -1.0f, 1.0f }, // v0
{ -1.0f, 1.0f, 1.0f }, // v1
{ 1.0f, 1.0f, 1.0f }, // v2
{ 1.0f, -1.0f, 1.0f }, // v3
{ -1.0f, -1.0f, -1.0f }, // v4
{ -1.0f, 1.0f, -1.0f }, // v5
{ 1.0f, 1.0f, -1.0f }, // v6
{ 1.0f, -1.0f, -1.0f }, // v7
};
int cubeIndices[] = {
0, 1, 2, 3, // Front Face
7, 6, 5, 4, // Back Face
2, 6, 7, 3, // Right Face
0, 4, 5, 1, // Left Face
1, 5, 6, 2, // Top Face
3, 7, 4, 0 // Bottom Face
};

float cubeColors[][3] = {
0, 1, 0, // Front is Green
1, 0, 0, // Back is Red
0, 0, 1, // Right is Blue
1, 1, 0, // Left is Yellow
0, 0, 0, // Top is Black
0.5, 0.5, 0.5 // Bottom is Grey
};int cubeNormals[][3] = {	{0,0,1},	{0,0,-1},	{1,0,0},	{-1,0,0},	{0,1,0},	{0,-1,0},};void Program::SetupLight() {
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

void DrawCube() {  //For Testing Only

	glEnable(GL_LIGHTING);
	GLfloat blue[] = { 0, 0, 1, 0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blue);
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW); // Front face is clockwise
	glPolygonMode(GL_FRONT, GL_FILL);
	glColor3f(0.0, 0.0, 0.0);
	// The index in cubeIndices array
	// points to next vertex to draw.
	int index = 0;
	// Draw the cube quad by quad
	for (int qd = 0; qd < 6; qd++) {
		glBegin(GL_QUADS);
		//glColor3f(cubeColors[qd][0], cubeColors[qd][1], cubeColors[qd][2]);
		glNormal3f(cubeNormals[qd][0], cubeNormals[qd][1], cubeNormals[qd][2]);
		for (int v = 0; v < 4; v++) {// Four vertices for one quad
			glVertex3f(cubeVertices[cubeIndices[index]][0],
				cubeVertices[cubeIndices[index]][1],
				cubeVertices[cubeIndices[index]][2]);
			index++; // Move to next vertex in quad
		}

		glEnd();
	}
	glDisable(GL_LIGHTING);
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

	DrawCube();
}

Program::~Program()
{
}
