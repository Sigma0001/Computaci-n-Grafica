#pragma once

#include <iostream>
#include "GL\glew.h"
#include <gl/GL.h>
#include <gl/GLU.h>

#include "glm/matrix.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/matrix_transform.hpp"


class Object3D{
public:
	GLuint	vao,vbo; 

	int numVertex; 


	GLuint shader[2]; 

	glm::mat4 rotation;

	

};

