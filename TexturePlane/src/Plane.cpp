#include "Plane.h"

Plane::Plane() : Object3D(),
					size(0),
					normals(NULL),
					plane(NULL),
					textureCoords(NULL),
					mTransform(glm::mat4(1.0)),
					aRotations(0.0f, 0.0f, 0.0f),
					side(0),
	                Light(-50.0f, 50.0f, 0.0f),
	                Ojo(0.0f, 90.0f, 80.0f)
{
}
void Plane::createPlane(int side)
{
	float gs = 100.0; 
	this->side = side;
	int TS = 2 * 3 * 2; 
	int VS = 2 * 3 * 4;

	int px = this->side, pz = this->side;
	size = px * VS * pz;
	int textureSize = px * TS * pz;

	plane = (GLfloat*)malloc(size * sizeof(GLfloat)); 
	textureCoords = (GLfloat*)malloc(textureSize * sizeof(GLfloat));

	
	GLfloat len = gs / (float)side,
		dx = len / 2.0,
		dz = len / 2.0;

	int colNorm = 0;
	int col = 0;
	int texCol = 0;
	for (int j = 0; j < pz; ++j)
		for (int i = 0; i < px; ++i, col += VS, texCol += TS)
		{
			GLfloat x = i * len - (gs / 2.0),
				z = j * len - (gs / 2.0);

			
			plane[col] = x;	
			plane[col + 1] = 0.0;				
			plane[col + 2] = z;	
			plane[col + 3] = 1.0;				
			textureCoords[texCol] = (float)i / (float)px;
			textureCoords[texCol + 1] = (float)j / (float)pz;

		
			plane[col + 4] = x;
			plane[col + 5] = 0.0;				
			plane[col + 6] = z + len;	
			plane[col + 7] = 1.0;				
			textureCoords[texCol + 2] = (float)i / (float)px;
			textureCoords[texCol + 3] = ((float)j + 1) / (float)pz;

																   
			plane[col + 8] = x + len;	
			plane[col + 9] = 0.0;				
			plane[col + 10] = z;	
			plane[col + 11] = 1.0;				
			textureCoords[texCol + 4] = ((float)i + 1) / (float)px;
			textureCoords[texCol + 5] = (float)j / (float)pz;

		
			plane[col + 12] = x;
			plane[col + 13] = 0.0;			
			plane[col + 14] = z + len;
			plane[col + 15] = 1.0;			
			textureCoords[texCol + 6] = (float)i / (float)px;
			textureCoords[texCol + 7] = ((float)j + 1) / (float)pz;

															
			plane[col + 16] = x + len;	
			plane[col + 17] = 0.0;				
			plane[col + 18] = z + len;	
			plane[col + 19] = 1.0;				
			textureCoords[texCol + 8] = ((float)i + 1) / (float)pz;
			textureCoords[texCol + 9] = ((float)j + 1) / (float)pz;

																   
			plane[col + 20] = x + len;
			plane[col + 21] = 0.0;	
			plane[col + 22] = z;
			plane[col + 23] = 1.0; 
			textureCoords[texCol + 10] = ((float)i + 1) / (float)px;
			textureCoords[texCol + 11] = (float)j / (float)pz;


			colNorm += 18;
		}

	

}

int Plane::getNumVertex()
{
	return size / 4;
}

void Plane::cleanMemory()
{
	if (normals)
	{
		free(normals);
		normals = NULL;
	}

	if (plane)
	{
		free(plane);
		plane = NULL;
	}

	if (textureCoords)
	{
		free(textureCoords);
		textureCoords = NULL;
	}
}

size_t Plane::getVertexSizeInBytes()
{
	int VS = 2 * 3 * 4;	 
	size = this->side * this->side * VS; 
	return size * sizeof(GLfloat);
}


size_t Plane::getTextureCoordsSizeInBytes()
{
	int TS = 2 * 3 * 2;	 
	int textureSize = this->side * this->side * TS; 

	return textureSize * sizeof(GLfloat);
}

Plane::~Plane()
{
	cleanMemory();
}

