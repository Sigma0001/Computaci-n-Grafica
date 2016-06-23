#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>


#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "Application.h"

Application app;



void setup()
{
	app.setup();
}


void display()
{
	app.display();
}


void reshape(int w, int h)
{
	app.reshape(w, h);
}

void keyboard(GLFWwindow *window, int key, int scanCode, int action, int mods)
{
	app.keyboard(key, scanCode, action, mods);
}

void cursor_pos_callback(GLFWwindow * window, double Xpos, double Ypos)
{
	app.cursor_position(Xpos, Ypos);
}


int main(int argc, char *argv[])
{

	GLFWwindow* window;

	
	if (!glfwInit())
		return -1;

	
	window = glfwCreateWindow(640, 480, "TexturePlane", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE; 
	glewInit();
	app.setup();

	
	const GLubyte* renderer = glGetString (GL_RENDERER); 
	const GLubyte* version = glGetString (GL_VERSION); 
	printf (" Renderer: %s\ n", renderer); 
	printf (" OpenGL version supported %s\ n", version); 
	
	
	glViewport(0, 0, (GLsizei)640, (GLsizei)480);

	glfwSetKeyCallback(window, keyboard); 

	glfwSetCursorPosCallback(window, cursor_pos_callback);

	while (!glfwWindowShouldClose(window))
	{
	
		glfwPollEvents();

		app.update();

		
		app.display();
		
		glfwSwapBuffers(window);
	}
	

	glfwTerminate();
	return 0;

}
