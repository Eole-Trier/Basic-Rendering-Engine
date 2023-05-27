#pragma once
#include <vector>

#include "Resource.h"
#include "Core/Maths/Vector2.h"
#include "Core/Maths/Vector3.h"
#include "Ressources/Shader.h"
#include "LowRenderer/Camera.h"

struct Vertex
{
	Vector3 Position;
	Vector3 Normal;
	Vector2 TextureUV;
};

class Model : public Resource
{
public:
	unsigned int VAO, VBO;
	unsigned int texture;
	Shader shader;

	Model();
	~Model();
	std::vector<Vertex> vertices;
	std::vector<uint32_t> indices;
    void Load(const char* modelPath, const char* texturePath);
	void Draw(Camera& camera);
	
};

