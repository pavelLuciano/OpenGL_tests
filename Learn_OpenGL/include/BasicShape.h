#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class BasicShape
{
private:
	unsigned int indices_size;
	unsigned int vertices_size;
	unsigned int textCoords_size; //que horror :c

public:
	int* indices;
	float* vertices;
	float* textCoords;
	BasicShape(int num_lados);
	BasicShape(int num_lados, float tam_radio, float altura);
	~BasicShape();
	
	void setTextCoords(int num_lados);
	unsigned int get_indices_size();
	unsigned int get_vertices_size();
	unsigned int get_textCoords_size();
	void LogIndices();
	void LogVertices();
	void LogTextCoords();
};

