///////////////////////////////DESCOMENTAR PARA MAPA DE ALTURA
//#version 430 core
//
//layout (location = 0) in vec4 vPosition;
//layout (location = 1) in vec2 vTexCo;
//
//uniform sampler2D Tex0;
//uniform mat4 mTransform;
//out vec2 texCo;
//uniform float fTime;                     
//                                        
//
//                     
//void main()
//{
//    vec4 Color = texture(Tex0, vTexCo);
//	texCo = vTexCo;
//	float lum = (0.299*Color.r + 0.587*Color.g + 0.114*Color.b);
//	vec4 nPos = vPosition; 
//	nPos.y = (8*lum);
//	//nPos.y = (8*lum*fTime); /*Cosas Locas*/
//	gl_Position = mTransform * nPos;
//}
////////////////////////////////

/////////////////////////////////COMENTAR PARA MAPA DE ALTURA
#version 430 core

layout (location = 0) in vec4 vPosition;
layout (location = 1) in vec2 vTexCo;

uniform mat4 mTransform;

out vec2 texCo;



void main()
{
	texCo = vTexCo;

	gl_Position = mTransform * vPosition;
}
////////////////////////////