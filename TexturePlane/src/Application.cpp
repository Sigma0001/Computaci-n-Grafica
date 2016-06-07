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
#include "SOIL.h"
#include "ShaderFuncs.h"

#include "Plane.h"


# define WIDTH 640.0f
# define HEIGHT 480.0f 


std::string strVertexShader, strFragmentShader;

Application::Application() : oPlane(),
							 fAngle(0.0),
							 fTime(),
							 eye(0.0f, 90.0f, 80.0f),
							 target(0.0f,0.0f,0.0f),
							 up(0.0f,1.0f,0.0f)
{}

Application::~Application() 
{}
void Application::Texture0()
{
	
	int img_width, img_height;
	int channels;
	
	//COMENTAR PARA MAPA DE ALTURA
	unsigned char* img = SOIL_load_image("Lenna.png", &img_width, &img_height, &channels, 0);
	//DESCOMENTAR PARA MAPA DE ALTURA
	//unsigned char* img = SOIL_load_image("dra.png", &img_width, &img_height, &channels, 0);
	
	

	glGenTextures(1, &oPlane.texture_id);
	glBindTexture(GL_TEXTURE_2D, oPlane.texture_id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img_width, img_height, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
	glTexStorage2D(GL_TEXTURE_2D, 0, GL_RGB, img_width, img_height);
	glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, img_width, img_height, GL_RGB, GL_UNSIGNED_BYTE, img);

	SOIL_free_image_data(img);

	glGenerateMipmap(GL_TEXTURE_2D);

	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);




	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_2D, 0);
}
void Application::Texture1()
{
	
	int img_width, img_height;
	int channels;

	//COMENTAR PARA MAPA DE ALTURA
	unsigned char* img = SOIL_load_image("rb.png", &img_width, &img_height, &channels, 0);
	//DESCOMENTAR PARA MAPA DE ALTURA
	//unsigned char* img = SOIL_load_image("dratex.png", &img_width, &img_height, &channels, 0);  
	

	glGenTextures(1, &oPlane.texture_id2);
	glBindTexture(GL_TEXTURE_2D, oPlane.texture_id2);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img_width, img_height, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
	glTexStorage2D(GL_TEXTURE_2D, 0, GL_RGB, img_width, img_height);
	glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, img_width, img_height, GL_RGB, GL_UNSIGNED_BYTE, img);

	SOIL_free_image_data(img);

	glGenerateMipmap(GL_TEXTURE_2D);

	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_2D, 1);
}


void Application::setup()
{
	Texture0();
	Texture1();
	oPlane.createPlane(20);
	
	std::string sVertex = loadTextFile("Shaders/passThru.v");
	std::string sFragment = loadTextFile("Shaders/passThru.f");
 

	InitializeProgram(oPlane.shader[0], sVertex, sFragment);
	InitializeProgram(oPlane.shader[1], sVertex, sFragment);

	oPlane.uTransform[0] = glGetUniformLocation(oPlane.shader[0], "mTransform");
	oPlane.uTime[0] = glGetUniformLocation(oPlane.shader[0], "fTime");
	
	oPlane.uTexture[0] = glGetUniformLocation(oPlane.shader[0], "Tex0");
	
	oPlane.uTransform[1] = glGetUniformLocation(oPlane.shader[0], "mTransform");
	oPlane.uTime[1] = glGetUniformLocation(oPlane.shader[1], "fTime");

	oPlane.uTexture2[1] = glGetUniformLocation(oPlane.shader[1], "Tex1");
	
	glGenVertexArrays(1, &oPlane.vao);
	glBindVertexArray(oPlane.vao);
	glGenBuffers(1, &oPlane.vbo);
	glBindBuffer(GL_ARRAY_BUFFER, oPlane.vbo);              

	glBufferData(GL_ARRAY_BUFFER, oPlane.getVertexSizeInBytes() + oPlane.getTextureCoordsSizeInBytes(), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, oPlane.getVertexSizeInBytes(), oPlane.plane);
	glBufferSubData(GL_ARRAY_BUFFER, oPlane.getVertexSizeInBytes(), oPlane.getTextureCoordsSizeInBytes(), oPlane.textureCoords); 

	oPlane.cleanMemory();

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)(oPlane.getVertexSizeInBytes()));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE);

}


void Application::display()
{
	
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); /*Lineas*/
	//glPolygonMode(GL_FRONT_AND_BACK, GL_POINT); /*Puntos*/

	mTra = glm::mat4(1.0);
	mTra = glm::rotate(mTra, oPlane.aRotations.x, glm::vec3(1.0, 0.0, 0.0));
	mTra = glm::rotate(mTra, oPlane.aRotations.y, glm::vec3(0.0, 1.0, 0.0));
	mTra = glm::rotate(mTra, oPlane.aRotations.z, glm::vec3(0.0, 0.0, 1.0));



	
	glUseProgram(oPlane.shader[0]);
	
	glUseProgram(oPlane.shader[1]);
	glm::mat4 transform = camera  *oPlane.rotation;
	transform = glm::perspective(45.0f, 640.0f/480.0f, 0.1f,200.0f)*transform*mTra;
	glUniformMatrix4fv(oPlane.uTransform[0],1,GL_FALSE, glm::value_ptr(transform));

	glUniform1f(oPlane.uTime[0] ,fTime);
	glUniform3fv(oPlane.Light[0], 1, glm::value_ptr(oPlane.Light));
	glUniform3fv(oPlane.Ojo[0], 1, glm::value_ptr(oPlane.Ojo));


	glUniform1i(oPlane.uTexture[1], 0);
    glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, oPlane.texture_id);

	
	glUniform1i(oPlane.uTexture2[1], 1);
	glActiveTexture(GL_TEXTURE1);                          
	glBindTexture(GL_TEXTURE_2D, oPlane.texture_id2); 



	
	glDrawArrays(GL_TRIANGLES, 0, oPlane.getNumVertex());
}

void Application::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

void Application::update()
{
	fAngle += 0.001;
	fTime = glfwGetTime();


	oPlane.rotation = glm::rotate(glm::mat4(1.0f), fTime, glm::vec3(0.0f, 1.0f, 0.0f));
	camera = glm::lookAt(eye, target, glm::vec3(0.0f, 1.0f, 0.0f));
}

void Application::keyboard(int key, int scanCode, int action, int mods)
{
}

void Application::cursor_position(double Xpos, double Ypos)
{
	oPlane.aRotations.y = -((Xpos - WIDTH) / 100.0f);
	oPlane.aRotations.x = ((Ypos + HEIGHT) / 100.0f);
}




