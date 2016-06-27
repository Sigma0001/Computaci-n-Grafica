/////////////DESCOMENTAR PARA MAPA DE ALTURA
//#version 430 core
//
//out vec4 fColor;
//in vec2 texCo;
//
//uniform sampler2D Tex0;
//uniform sampler2D Tex1;
//                                  
//                                  
//void main()
//{
//    fColor = texture(Tex1, texCo);
//}
///////////////

/////////////COMENTAR PARA MAPA DE ALTURA
#version 430 core

out vec4 fColor;
in vec2 texCo;

uniform sampler2D Tex0;
uniform sampler2D Tex1;


void main()
{
    fColor = texture(Tex0, texCo) * texture(Tex1, texCo);
}
//////////////////////////
