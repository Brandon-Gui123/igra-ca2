#include "TimerBarMesh.h"


float cubeVerticesC[][3] = {
	{ -0.6f, -0.2f, 0.6f }, // v0
	{ -0.6f, 0.2f, 0.6f }, // v1
	{ 0.6f, 0.2f, 0.6f }, // v2
	{ 0.6f, -0.2f, 0.6f }, // v3
	{ -0.6f, -0.2f, -4.0f }, // v4
	{ -0.6f, 0.2f, -4.0f }, // v5
	{ 0.6f, 0.2f, -4.0f }, // v6
	{ 0.6f, -0.2f, -4.0f }, // v7
};

int cubeIndicesC[] = {
	0, 1, 2, 3, // Front Face
	7, 6, 5, 4, // Back Face
	2, 6, 7, 3, // Right Face
	0, 4, 5, 1, // Left Face
	1, 5, 6, 2, // Top Face
	3, 7, 4, 0 // Bottom Face
};

float cubeColorsC[][3] = {
	0, 1, 0, // Front is Green
	1, 0, 0, // Back is Red
	0, 0, 1, // Right is Blue
	1, 1, 0, // Left is Yellow
	0, 0, 0, // Top is Black
	0.5, 0.5, 0.5 // Bottom is Grey
};

int cubeNormalsC[][3] = {
	{0,0,1},
	{0,0,-1},
	{1,0,0},
	{-1,0,0},
	{0,1,0},
	{0,-1,0},
};

float cubeTextureMapC[][2]{
	{0,0},
	{0,1.0},
	{1.0,1.0},
	{1.0,0}
};

void TimerBarMesh::DrawShape()
{
	TimerBarMaterial.SetMaterial();
	glEnable(GL_CULL_FACE);
	{
		glFrontFace(GL_CW); // Front face is clockwise
		glPolygonMode(GL_FRONT, GL_FILL);

		// The index in cubeIndices array
		// points to next vertex to draw.
		int index = 0;

			// Draw the cube quad by quad
		for (int qd = 0; qd < 6; qd++) {
			glBegin(GL_POLYGON);
			{
				glNormal3f(cubeNormalsC[qd][0], cubeNormalsC[qd][1], cubeNormalsC[qd][2]);
				for (int v = 0; v < 4; v++) {// Four vertices for one quad
					glTexCoord2f(cubeTextureMapC[v][0], cubeTextureMapC[v][1]);
					glVertex3f(cubeVerticesC[cubeIndicesC[index]][0],
					cubeVerticesC[cubeIndicesC[index]][1] - 0.1f,
					cubeVerticesC[cubeIndicesC[index]][2]);
					index++; // Move to next vertex in quad
				}
			}
			glEnd();
		}
	}
	glDisable(GL_CULL_FACE);
}

TimerBarMesh::TimerBarMesh()
{
}


TimerBarMesh::~TimerBarMesh()
{
}
