
#include "Application.h"
#include <iostream>
#include <vector>

#include "GLFW/glfw3.h"
#include "GL\glew.h"
#include <gl/GL.h>
#include <gl/GLU.h>

#include "glm/matrix.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/matrix_transform.hpp"
//#include "GL/freeglut.h"

#include "ShaderFuncs.h"


char Laberint[10][10] = { 1,1,1,1,1,1,1,1,1,1,
						  1,0,0,0,0,0,0,0,0,1,
						  1,0,1,0,0,0,0,1,0,1,
						  1,0,0,0,0,0,0,0,0,1,
						  1,0,0,0,0,0,0,0,0,1,
						  1,0,1,0,0,0,0,1,0,1,
						  1,0,0,1,1,1,1,0,0,1,
						  1,0,0,0,0,0,0,0,0,1,
						  1,0,0,0,0,0,0,0,0,1,
						  1,1,1,1,1,1,1,1,1,1 };

GLfloat vertexPositions[] =
{
	//trasera
	1.0f, 1.0f, -1.0f, 1.0f,
	1.0f, -1.0f, -1.0f, 1.0f,
	-1.0f, -1.0f, -1.0f, 1.0f,

	1.0f, 1.0f, -1.0f, 1.0f,
	-1.0f, -1.0f, -1.0f, 1.0f,
	-1.0f, 1.0f, -1.0f, 1.0f,

	//frente
	1.0f, 1.0f, 1.0f, 1.0f,
	-1.0f, -1.0f, 1.0f, 1.0f,
	1.0f, -1.0f, 1.0f, 1.0f,

	1.0f, 1.0f, 1.0f, 1.0f,
	-1.0f, 1.0f, 1.0f, 1.0f,
	-1.0f, -1.0f, 1.0f, 1.0f,

	//Derecha roja
	1.0f, 1.0f, 1.0f, 1.0f,
	1.0f, -1.0f, 1.0f, 1.0f,
	1.0f, -1.0f, -1.0f, 1.0f,


	1.0f, -1.0f, -1.0f, 1.0f,
	1.0f, 1.0f, -1.0f, 1.0f,
	1.0f, 1.0f, 1.0f, 1.0f,

	//izquierda
	-1.0f, 1.0f, -1.0f, 1.0f,
	-1.0f, -1.0f, -1.0f, 1.0f,
	-1.0f, -1.0f, 1.0f, 1.0f,

	-1.0f, 1.0f, -1.0f, 1.0f,
	-1.0f, -1.0f, 1.0f, 1.0f,
	-1.0f, 1.0f, 1.0f, 1.0f,

	//techo
	-1.0f, 1.0f, -1.0f, 1.0f,
	-1.0f, 1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f, 1.0f,

	-1.0f, 1.0f, -1.0f, 1.0f,
	1.0f, 1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, -1.0f, 1.0f,


	//piso
	-1.0f, -1.0f, 1.0f, 1.0f,
	-1.0f, -1.0f, -1.0f, 1.0f,
	1.0f, -1.0f, -1.0f, 1.0f,

	-1.0f, -1.0f, 1.0f, 1.0f,
	1.0f, -1.0f, -1.0f, 1.0f,
	1.0f, -1.0f, 1.0f, 1.0f
};

GLfloat vertexColors[] =
{
	//trasera
	0.0f, 0.0f, 1.0f,1.0f,
	0.0f, 0.0f, 1.0f,1.0f,
	0.0f, 0.0f, 1.0f,1.0f,
					 
	0.0f, 0.0f, 1.0f,1.0f,
	0.0f, 0.0f, 1.0f,1.0f,
	0.0f, 0.0f, 1.0f,1.0f,

	//frente
	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,

	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,

	//derecha roja
	1.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f,

	1.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f, 1.0f,

	//izquierda naranja
	1.0f, 0.5f, 0.0f, 1.0f,
	1.0f, 0.5f, 0.0f, 1.0f,
	1.0f, 0.5f, 0.0f, 1.0f,

	1.0f, 0.5f, 0.0f, 1.0f,
	1.0f, 0.5f, 0.0f, 1.0f,
	1.0f, 0.5f, 0.0f, 1.0f,

	//techo
	1.0f, 1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f, 1.0f,

	1.0f, 1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f, 1.0f,

	//piso
	1.0f, 1.0f, 0.0f, 1.0f,
	1.0f, 1.0f, 0.0f, 1.0f,
	1.0f, 1.0f, 0.0f, 1.0f,

	1.0f, 1.0f, 0.0f, 1.0f,
	1.0f, 1.0f, 0.0f, 1.0f,
	1.0f, 1.0f, 0.0f, 1.0f

};


std::string strVertexShader, strFragmentShader;

Application::Application() : fAngle(0.0),
							 eye(0.0f,40.0f,10.0f),
							 target(0.0f,0.0f,0.0f),
							 up(0.0f,1.0f,0.0f)
{}

Application::~Application() 
{}


void Application::loadShaders()
{
	strVertexShader = loadTextFile("Shaders/VertexShaders_1.vs");
	strFragmentShader = loadTextFile("Shaders/FragmentShader_1.fs");
}
void Application::setup()
{
	loadShaders();
	InitializeProgram(cube.shader, strVertexShader, strFragmentShader);
	uTransform = glGetUniformLocation(cube.shader, "transform");

	cube.numVertex = sizeof (vertexPositions)/4;
	glGenVertexArrays(1, &cube.vao);
	glBindVertexArray(cube.vao);
	glGenBuffers(1, &cube.vbo);
	glBindBuffer(GL_ARRAY_BUFFER, cube.vbo);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions), vertexPositions, GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexPositions)+sizeof(vertexColors), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0/*offset*/, sizeof(vertexPositions), vertexPositions);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertexPositions), sizeof(vertexColors), vertexColors);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)sizeof(vertexPositions));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glEnable(GL_CULL_FACE);

}


void Application::display()
{
	//Borramos el buffer de color
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	//Seleccionamos los shaders a usar
	glUseProgram(cube.shader);	
	glm::mat4 transform = camera*cube.rotation;
	transform = glm::perspective(45.0f, 640.0f/480.0f, 0.1f,200.0f)*transform;

	glUniformMatrix4fv(uTransform,1,GL_FALSE, glm::value_ptr(transform));
	
	//activamos el vertex array object y dibujamos
	glBindVertexArray(cube.vao);

	for (int j = 0; j < 10; j++)
	{
		glm::mat4 position2 = glm::translate(glm::mat4(1.0f), (glm::vec3(2.0f, 2.0f, 2.0f*j)));

		for (int i = 0; i < 10; i++)
		{
			glm::mat4 position = glm::translate(glm::mat4(1.0f), (glm::vec3(2.0f*i, 2.0f, 1.0f)));
			position = glm::translate(position, glm::vec3(-10.0f, -10.0f, 0.9f));
			
			glm::mat4 transform = camera * position * position2;
			transform = glm::perspective(45.0f, 680.0f / 480.0f, 0.1f, 200.0f) * transform;
			if (Laberint[i][j] == 1)
			{
				glUniformMatrix4fv(uTransform, 1, GL_FALSE, glm::value_ptr(transform));

				glDrawArrays(GL_TRIANGLES, 0, cube.numVertex);
			}
			
		}
	}


	//glDrawArrays(GL_TRIANGLES, 0, cube.numVertex);
}

void Application::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

void Application::update()
{
	//fAngle += 0.001;
	fAngle = glfwGetTime();
	//std::cout << fAngle << std::endl;

	cube.rotation = glm::rotate(glm::mat4(1.0f), fAngle, glm::vec3(0.0f, 1.0f, 0.0f));
	camera = glm::lookAt(eye, target,up);
}

void Application::keyboard(int key, int scanCode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		exit(0);
	if (action == GLFW_RELEASE)
		return;


	switch (key)
	{
	case GLFW_KEY_W: avanza(); break;
	case GLFW_KEY_A: Izq(); break;
	}
}

void Application::avanza()
{
	//glm::vec3 dir = target - eye;
	//dir = 
}

void Application::Izq()
{
}



