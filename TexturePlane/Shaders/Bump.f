#version 430 core

out vec4 fColor;
in vec2 texCo;
in vec3 vEye;

uniform mat4 mTransform;
uniform sampler2D Texture;
uniform sampler2D NormMap;
vec4 lPos; 

const float chainy = 40.0;

const vec3 A = vec3( 0.2, 0.2, 0.2 );
const vec3 D = vec3( 1.0, 1.0, 1.0 );
const vec3 S = vec3( 1.0, 1.0, 1.0 );

const vec3 Am = vec3( 0.7, 0.9, 0.0 );
const vec3 Dm = vec3( 0.3, 1.0, 0.0 );
const vec3 Sm = vec3( 0.7, 0.7, 0.7 );

vec3 Ambient()
{
	return A * Am;
}

vec3 Diffuse (in vec3 veclight, in vec3 norma)
{
	return max(0.0, dot(veclight, norma)) * Dm * D;
}

vec3 Specular(in vec3 veclight, in vec3 norma)
{
	vec3 refl = reflect( vec3(0.,0.,0.) - veclight, norma );
	vec3 viewv = normalize( vec3(0.,0.,0.) - vEye );

	vec3 specular = vec3( 0.0, 0.0, 0.0 );
	if( dot(veclight, viewv) > 0.0)
	{
		specular = pow(max(0.0, dot(viewv,refl)), chainy) * Sm * S;
	}
	return specular;	
}

vec3 ADS( in vec3 myNormal, in vec3 myPosition )
{
	vec3 norma = normalize( myNormal );
	vec3 veclight = normalize( lPos.xyz - myPosition);

	vec3 ambient = Ambient();
	vec3 diffuse = Diffuse(veclight, norma); 
	vec3 specular = Specular (veclight, norma);
	
	return clamp( ambient + diffuse, 0.0, 1.0);
}

void main()
{
	lPos = vec4(1.0 , 1.0, 1.0, 1.0);
	lPos = mTransform * lPos;
    mat4 DemNormals = transpose(inverse(mTransform));
	vec3 normal = texture(NormMap, texCo).rgb;
	vec3 newNormal = (DemNormals * vec4(normal, 1.0)).xyz;
	fColor = vec4(ADS(newNormal, vEye), 1.0) * texture(Texture, texCo);
}