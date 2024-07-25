#include "Mesh.h"

/*
Es posible utilizar std::move para mover los valores de los vectores en vez de copiarlos (lo cual es más eficiente)
esto si no son modificados despues de ser dados al constructor (revisar la documentación)
*/

Mesh::Mesh(
	const std::vector<Vertex>& vertices,
	const std::vector<unsigned int>& indices,
	const std::vector<Texture>& textures
) : vertices(vertices), indices(indices), textures(textures)
{
	setupMesh();
}

void Mesh::setupMesh()
{
	glGenVertexArrays(1,  &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

	//Position
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	//Normal
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
	//Texture Coords
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));
}

void Mesh::Draw(Shader& shader)
{

}