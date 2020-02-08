#include "PlayerMesh.h"

#include "Program.h"
#include "Vector3f.h"

#include "framework.h"
#include <gl/GL.h>  // OpenGL 32-bit library
#include <gl/GLU.h> // OpenGL Utilities 32-bit library

#include <iostream>   // std::cout
#include <string>     // std::string, std::to_string
#include <vector>

float cubeVerticesA[][3] = {
	{ -1.0f, -1.0f, 1.0f }, // v0
	{ -1.0f, 1.0f, 1.0f }, // v1
	{ 1.0f, 1.0f, 1.0f }, // v2
	{ 1.0f, -1.0f, 1.0f }, // v3
	{ -1.0f, -1.0f, -1.0f }, // v4
	{ -1.0f, 1.0f, -1.0f }, // v5
	{ 1.0f, 1.0f, -1.0f }, // v6
	{ 1.0f, -1.0f, -1.0f }, // v7
};

int cubeIndicesA[] = {
	0, 1, 2, 3, // Front Face
	7, 6, 5, 4, // Back Face
	2, 6, 7, 3, // Right Face
	0, 4, 5, 1, // Left Face
	1, 5, 6, 2, // Top Face
	3, 7, 4, 0 // Bottom Face
};

float cubeColorsA[][3] = {
	0, 1, 0, // Front is Green
	1, 0, 0, // Back is Red
	0, 0, 1, // Right is Blue
	1, 1, 0, // Left is Yellow
	0, 0, 0, // Top is Black
	0.5, 0.5, 0.5 // Bottom is Grey
};

int cubeNormalsA[][3] = {
	{0,0,1},
	{0,0,-1},
	{1,0,0},
	{-1,0,0},
	{0,1,0},
	{0,-1,0},
};

float cubeTextureMapA[][2]{
	{0,0},
	{0,1.0},
	{1.0,1.0},
	{1.0,0}
};

void PlayerMesh::DrawShape()
{
	glPushMatrix();
	glTranslatef(0, 0.8f, 0); //Offset

	//GLfloat matcolour[] = { 1, 1, 0, 1 };
	//glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, matcolour);
	
	bodyMaterial.SetMaterial();

	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW); // Front face is clockwise
	glPolygonMode(GL_FRONT, GL_FILL);//glEnable(GL_TEXTURE_2D);
	int index = 0;

	/////////// HEAD ////////////

	for (int qd = 0; qd < 6; qd++) {
		glBegin(GL_POLYGON);
		glNormal3f(cubeNormalsA[qd][0], cubeNormalsA[qd][1], cubeNormalsA[qd][2]);
		for (int v = 0; v < 4; v++) {// Four vertices for one quad
			glTexCoord2f(cubeTextureMapA[v][0], cubeTextureMapA[v][1]);
			glVertex3f(cubeVerticesA[cubeIndicesA[index]][0] * 0.5,
				cubeVerticesA[cubeIndicesA[index]][1] * 0.5 + 0.6,
				cubeVerticesA[cubeIndicesA[index]][2] * 0.5 + 0.6);
			index++; // Move to next vertex in quad
		}

		glEnd();
	}

	/////////// BODY ////////////
	index = 0;

	for (int qd = 0; qd < 6; qd++) {
		glBegin(GL_POLYGON);
		glNormal3f(cubeNormalsA[qd][0], cubeNormalsA[qd][1], cubeNormalsA[qd][2]);
		for (int v = 0; v < 4; v++) {// Four vertices for one quad
			glTexCoord2f(cubeTextureMapA[v][0], cubeTextureMapA[v][1]);
			glVertex3f(cubeVerticesA[cubeIndicesA[index]][0] * 0.3,
				cubeVerticesA[cubeIndicesA[index]][1] * 0.3,
				cubeVerticesA[cubeIndicesA[index]][2] * 0.3);
			index++; // Move to next vertex in quad
		}

		glEnd();
	}

	/////////// ORANGE ////////////

	//GLfloat matcolour2[] = { 1, 0.5, 0, 1 };
	//glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, matcolour2);

	billMaterial.SetMaterial();

	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW); // Front face is clockwise
	glPolygonMode(GL_FRONT, GL_FILL);

	/////////// BEAK ////////////
	index = 0;

	for (int qd = 0; qd < 6; qd++) {
		glBegin(GL_POLYGON);
		glNormal3f(cubeNormalsA[qd][0], cubeNormalsA[qd][1], cubeNormalsA[qd][2]);
		for (int v = 0; v < 4; v++) {// Four vertices for one quad
			glTexCoord2f(cubeTextureMapA[v][0], cubeTextureMapA[v][1]);
			glVertex3f(cubeVerticesA[cubeIndicesA[index]][0] * 0.2,
				cubeVerticesA[cubeIndicesA[index]][1] * 0.1 + 0.45,
				cubeVerticesA[cubeIndicesA[index]][2] * 0.2 + 1.1);
			index++; // Move to next vertex in quad
		}

		glEnd();
	}

	/////////// LEG1 ////////////
	legsMaterial.SetMaterial();
	index = 0;

	for (int qd = 0; qd < 6; qd++) {
		glBegin(GL_POLYGON);
		glNormal3f(cubeNormalsA[qd][0], cubeNormalsA[qd][1], cubeNormalsA[qd][2]);
		for (int v = 0; v < 4; v++) {// Four vertices for one quad
			glTexCoord2f(cubeTextureMapA[v][0], cubeTextureMapA[v][1]);
			glVertex3f(cubeVerticesA[cubeIndicesA[index]][0] * 0.06 + 0.17,
				cubeVerticesA[cubeIndicesA[index]][1] * 0.4 - 0.4,
				cubeVerticesA[cubeIndicesA[index]][2] * 0.06);
			index++; // Move to next vertex in quad
		}

		glEnd();
	}

	/////////// LEG2 ////////////
	index = 0;

	for (int qd = 0; qd < 6; qd++) {
		glBegin(GL_POLYGON);
		glNormal3f(cubeNormalsA[qd][0], cubeNormalsA[qd][1], cubeNormalsA[qd][2]);
		for (int v = 0; v < 4; v++) {// Four vertices for one quad
			glTexCoord2f(cubeTextureMapA[v][0], cubeTextureMapA[v][1]);
			glVertex3f(cubeVerticesA[cubeIndicesA[index]][0] * 0.06 - 0.17,
				cubeVerticesA[cubeIndicesA[index]][1] * 0.4 - 0.4,
				cubeVerticesA[cubeIndicesA[index]][2] * 0.06);
			index++; // Move to next vertex in quad
		}

		glEnd();
	}

	/////////// BLACK ////////////

	//GLfloat matcolour3[] = { 0, 0, 0, 1 };
	//glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, matcolour3);

	eyeMaterial.SetMaterial();

	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW); // Front face is clockwise
	glPolygonMode(GL_FRONT, GL_FILL);


	/////////// EYE1 ////////////
	index = 0;

	for (int qd = 0; qd < 6; qd++) {
		glBegin(GL_POLYGON);
		glNormal3f(cubeNormalsA[qd][0], cubeNormalsA[qd][1], cubeNormalsA[qd][2]);
		for (int v = 0; v < 4; v++) {// Four vertices for one quad
			glTexCoord2f(cubeTextureMapA[v][0], cubeTextureMapA[v][1]);
			glVertex3f(cubeVerticesA[cubeIndicesA[index]][0] * 0.06 + 0.35,
				cubeVerticesA[cubeIndicesA[index]][1] * 0.06 + 0.75,
				cubeVerticesA[cubeIndicesA[index]][2] * 0.06 + 1.1);
			index++; // Move to next vertex in quad
		}

		glEnd();
	}

	/////////// EYE2 ////////////
	index = 0;

	for (int qd = 0; qd < 6; qd++) {
		glBegin(GL_POLYGON);
		glNormal3f(cubeNormalsA[qd][0], cubeNormalsA[qd][1], cubeNormalsA[qd][2]);
		for (int v = 0; v < 4; v++) {// Four vertices for one quad
			glTexCoord2f(cubeTextureMapA[v][0], cubeTextureMapA[v][1]);
			glVertex3f(cubeVerticesA[cubeIndicesA[index]][0] * 0.06 - 0.35,
				cubeVerticesA[cubeIndicesA[index]][1] * 0.06 + 0.75,
				cubeVerticesA[cubeIndicesA[index]][2] * 0.06 + 1.1);
			index++; // Move to next vertex in quad
		}

		glEnd();
	}

	glDisable(GL_CULL_FACE);
	glPopMatrix();
}

PlayerMesh::PlayerMesh()
{
}

PlayerMesh::~PlayerMesh()
{
}
