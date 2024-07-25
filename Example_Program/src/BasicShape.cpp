#include "BasicShape.h"
#include <iostream>

BasicShape::BasicShape(int num_lados, float tam_radio, float altura)
{
	altura /= 2;
	if (num_lados < 3) num_lados = 3;
	this->vertices_size = (num_lados * 3 + 3) * 2;
	this->indices_size = (num_lados * 3 * 2) * 2;
	this->textCoords_size = (num_lados * 2 + 2) * 2;
	this->vertices = new float[this->vertices_size];
	this->indices = new int[this->indices_size];
	this->textCoords = new float[this->textCoords_size];
	//tomaremos un punto y lo rotaremos para ir guardando las coordenadas de los vertices de nuestro poligono regular
	float degree_angle = 360.0f / num_lados;
	float theta = glm::radians(degree_angle);
	glm::mat2 matrizRotacion = glm::mat2( glm::cos(theta),  glm::sin(theta),
										 -glm::sin(theta),  glm::cos(theta));
	glm::vec2 punto(tam_radio, 0.0f);
	//coordenadas de los vertices y de las texturas
	unsigned int i, j;
	for (i = 0; i < 2; i++)
	{
		this->vertices[i] = 0.0f;
		this->vertices[i + num_lados * 3 + 3] = 0.0f;
	}
	for (j = 0; j < 2; j++)
	{
		this->textCoords[j] = 0.5f;
		this->textCoords[j + num_lados * 2 + 2] = 0.5f;
	}
	this->vertices[i] = altura;
	this->vertices[i + num_lados*3 + 3] = -altura;
	i++;
	for (; i < this->vertices_size/2; i += 3)
	{
		punto = matrizRotacion * punto;
		this->vertices[i] = punto.x;
		this->vertices[i + 1] = punto.y;
		this->vertices[i + 2] = altura;
		this->vertices[i + num_lados*3 + 3] = punto.x;
		this->vertices[i + num_lados*3 + 4] = punto.y;
		this->vertices[i + num_lados*3 + 5] = -altura;
		this->textCoords[j] = punto.x + 0.5f;
		this->textCoords[j + 1] = punto.y + 0.5f;
		this->textCoords[j + num_lados * 2 + 2] = punto.x + 0.5f;
		this->textCoords[j + num_lados * 2 + 3] = punto.y + 0.5f;
		j+=2;
	}

	//Indices
	this->indices[0] = 0;
	this->indices[1] = num_lados;
	this->indices[2] = 1;
	this->indices[num_lados * 3] = num_lados + 1;
	this->indices[num_lados * 3 + 1] = num_lados * 2 + 1;
	this->indices[num_lados * 3 + 2] = num_lados + 2;
	int k = 4;
	for (int n = 1; n < num_lados; n++)
	{
		this->indices[k - 1] = 0;
		this->indices[k] = n;
		this->indices[k + 1] = n + 1;
		this->indices[k - 1 + num_lados * 3] = num_lados + 1;
		this->indices[k + num_lados * 3] = num_lados + 1 + n;
		this->indices[k + 1 + num_lados * 3] = num_lados + 2 + n;
		k += 3;
	}
	k = num_lados * 3 * 2;
	this->indices[k] = num_lados;
	this->indices[k + 1] = num_lados * 2 + 1;
	this->indices[k + 2] = num_lados + 2;
	this->indices[k + 3] = num_lados;
	this->indices[k + 4] = 1;
	this->indices[k + 5] = num_lados + 2;
	k += 6;
	for (int n = 1; n < num_lados; n++)
	{
		this->indices[k] = n;
		this->indices[k + 1] = num_lados + 1 + n;
		this->indices[k + 2] = num_lados + 2 + n;
		this->indices[k + 3] = n;
		this->indices[k + 4] = n + 1;
		this->indices[k + 5] = num_lados + 2 + n;
		k += 6;
	}
}
BasicShape::BasicShape(int num_lados) : BasicShape(num_lados, 0.25f, 1.0f){}
BasicShape::~BasicShape()
{
	delete[] vertices;
	delete[] indices;
}


void BasicShape::LogIndices()
{
	std::cout << "INDICES: \n";
	for (int i = 0; i < indices_size; i += 3)
	{
		std::cout << indices[i] << " " << indices[i + 1] << " " << indices[i + 2] << "\n";
	}
}

void BasicShape::LogVertices()
{
	std::cout << "VERTICES: \n";
	for (int i = 0; i < vertices_size; i+=3)
	{
		std::cout << vertices[i] << " " << vertices[i+1] << " " << vertices[i+2] << "\n";
	}
}

void BasicShape::LogTextCoords()
{
	std::cout << "TEXT CORDS: \n";
	for(int i = 0; i < textCoords_size; i+=2)
	{
		std::cout << textCoords[i] << " " << textCoords[i + 1] << "\n";
	}
}

unsigned int BasicShape::get_indices_size()
{
	return this->indices_size * sizeof(float);
}

unsigned int BasicShape::get_vertices_size()
{
	return this->vertices_size * sizeof(float);
}

unsigned int BasicShape::get_textCoords_size()
{
	return this->textCoords_size * sizeof(float);
}

void BasicShape::setTextCoords(int num_lados)
{

}

