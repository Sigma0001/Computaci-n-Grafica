#pragma once

#include <iostream>
#include "Object3D.h"

#include "glm/matrix.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "Plane.h"

class Application {
public:
	Application();
	~Application();

	void setup();
	void display();
	void reshape(int w, int h);
	void update();
	void keyboard(int key, int scanCode, int action, int mods);
	void cursor_position(double Xpos, double Ypos);
	void Texture0();
    void Texture1();
	
private:	
	Object3D cube;

	//void loadShaders();
	GLint uTransform;
	float fAngle;
	float fTime;
	Plane oPlane;

	glm::mat4 camera, mTra;
	
	glm::vec3 eye, target, up;
	
};


