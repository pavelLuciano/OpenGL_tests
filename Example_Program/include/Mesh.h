#ifndef _MESH_H
#define _MESH_H
#include <Gl/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <vector>
#include "Shader.h"

struct Vertex
{
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
};
struct Texture
{
	unsigned int id;
	std::string type;
};

class Mesh
{
private: 
	unsigned int VBO, EBO, VAO;
	void setupMesh();

public:
	std::vector<Vertex>       vertices;
	std::vector<unsigned int> indices;
	std::vector<Texture>      textures;

	Mesh(
		const std::vector<Vertex>& vertices,
		const std::vector<unsigned int>& indices,
		const std::vector<Texture>& textures
	);
	void Draw(Shader& shader);
};

#endif

