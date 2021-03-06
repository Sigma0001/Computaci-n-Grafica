
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

#include "ShaderFuncs.h"

#include "Plane.h"


# define WIDTH 640.0f
# define HEIGHT 480.0f 


std::string strVertexShader, strFragmentShader;

Application::Application() : oPlane(),
							 fAngle(0.0),
							 fTime(),
							 eye(0.0f,90.0f,80.0f),
							 target(0.0f,0.0f,0.0f),
							 up(0.0f,1.0f,0.0f),
							 light(-50.0f, 0.0f, 0.0f)
{}

Application::~Application() 
{}


//void Application::loadShaders()
//{
//	strVertexShader = loadTextFile("Shaders/VertexShaders_1.vs");
//	strFragmentShader = loadTextFile("Shaders/FragmentShader_1.fs");
//}
void Application::setup()
{
	oPlane.createPlane(420);
	std::string sVertex = loadTextFile("Shaders/gouraudPlane.v");
	//std::string sVertex = loadTextFile("Shaders/passThru.v");
	std::string sFragment = loadTextFile("Shaders/passThru.f");
	
	InitializeProgram(oPlane.shader[0], sVertex, sFragment);
	//InitializeProgram(oPlane.shader[1], sVertex, sFragment);

	

	oPlane.uTransform[0] = glGetUniformLocation(oPlane.shader[0], "mTransform");
	oPlane.uTime[0] = glGetUniformLocation(oPlane.shader[0], "fTime");
	oPlane.myLightPosition[0] = glGetUniformLocation(oPlane.shader[0], "myLightPosition");
	oPlane.vEye[0] = glGetUniformLocation(oPlane.shader[0], "vEye");

	
	oPlane.uTransform[1] = glGetUniformLocation(oPlane.shader[1], "mTransform");
	oPlane.uTime[1] = glGetUniformLocation(oPlane.shader[1], "fTime");
	//oPlane.vEye[1] = glGetUniformLocation(oPlane.shader[1], "vEye");
	//oPlane.myLightPosition[1] = glGetUniformLocation(oPlane.shader[1], "myLightPosition");

	
	glGenVertexArrays(1, &oPlane.vao);
	glBindVertexArray(oPlane.vao);
	glGenBuffers(1, &oPlane.vbo);
	glBindBuffer(GL_ARRAY_BUFFER, oPlane.vbo);

	glBufferData(GL_ARRAY_BUFFER, oPlane.getVertexSizeInBytes(), NULL, GL_STATIC_DRAW);
	
	glBufferSubData(GL_ARRAY_BUFFER, 0, oPlane.getVertexSizeInBytes(), oPlane.plane);

	oPlane.cleanMemory();

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	//glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)(oPlane.getVertexSizeInBytes()));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	//glEnable(GL_CULL_FACE);

}


void Application::display()
{
	//Borramos el buffer de color
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); /*Lineas*/
	//glPolygonMode(GL_FRONT_AND_BACK, GL_POINT); /*Puntos*/


	mTra = glm::mat4(1.0);
	mTra = glm::rotate(mTra, oPlane.aRotations.x, glm::vec3(1.0, 0.0, 0.0));
	mTra = glm::rotate(mTra, oPlane.aRotations.y, glm::vec3(0.0, 1.0, 0.0));
	mTra = glm::rotate(mTra, oPlane.aRotations.z, glm::vec3(0.0, 0.0, 1.0));

	//Seleccionamos los shaders a usar
	glUseProgram(oPlane.shader[0]);
	glm::mat4 transform = camera*oPlane.rotation;
	transform = glm::perspective(45.0f, 640.0f/480.0f, 0.1f,200.0f)*transform*mTra;
	glUniformMatrix4fv(oPlane.uTransform[0],1,GL_FALSE, glm::value_ptr(transform));
	glUniform1f(oPlane.uTime[0] ,fTime);
	glUniform3fv(oPlane.myLightPosition[0], 1, glm::value_ptr(light));
	glUniform3fv(oPlane.vEye[0], 1, glm::value_ptr(eye));
	//activamos el vertex array object y dibujamos


	glDrawArrays(GL_TRIANGLES, 0, oPlane.size);
}

void Application::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

void Application::update()
{
	//fAngle += 0.001;
	fTime = glfwGetTime();
	//std::cout << fAngle << std::endl;

	oPlane.rotation = glm::rotate(glm::mat4(1.0f), fTime, glm::vec3(0.0f, 1.0f, 0.0f));
	camera = glm::lookAt(eye, target, glm::vec3(0.0f, 1.0f, 0.0f));
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

void Application::cursor_position(double Xpos, double Ypos)
{
	oPlane.aRotations.y = -((Xpos - WIDTH / 2.0f) / 100.0f);
	oPlane.aRotations.x = ((Ypos + HEIGHT / 2.0f) / 100.0f);
}

void Application::avanza()
{
	//glm::vec3 dir = target - eye;
	//dir = 
}

void Application::Izq()
{
}



