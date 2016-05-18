#version 430 core
layout (location = 0) in vec4 vPosition;

uniform mat4 mTransform;
uniform float fTime;

vec4 mathFunc (vec4 r)
{
//r.y = 4.0*cos(fTime)*(0.01*(r.x * r.x + r.z * r.z) + fTime); 
//r.y = 3.0*cos(fTime)*sin(0.01*(r.x * r.x + r.z * r.z) + fTime); 
r.y = 4.0*sin(0.01*(r.x * r.x + r.z * r.z) + fTime);
//r.y = 1.5*cos(0.01*(r.x * r.z + r.z * r.z) + fTime);
//r.y = 1.5*cos(0.01*(r.x * r.y + r.z * r.z) + fTime);
//r.y = fTime*cos(fTime*(r.x * r.x + r.z * r.z) + fTime);
//r.y = 1.5*cos(0.04*(r.x * r.x + r.z * r.z) + fTime);
//r.y = 1.5*cos(0.01*(r.x * r.x + r.z * r.z) + fTime); /*Esta el la chida*/
//r.y = 4.0*cos(0.02*(r.x * r.x + r.z * r.z) +fTime);
return r;
}

void main()
{
gl_Position = mTransform * mathFunc(vPosition);
}