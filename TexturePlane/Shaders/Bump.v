#version 430 core

uniform mat4 mTransform;
//uniform float fTime; 
layout (location = 0) in vec4 vPos;
layout (location = 1) in vec2 vTexCo;
out vec2 texCo; 
varying vec3 vEye;

void main()
{
	texCo = vTexCo;
	gl_Position = mTransform * vPos;
}