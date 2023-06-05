#include <iostream>
#include <fstream>
#include <string>
#include "Ressources/Model.h"
#include "Core/Debug/Log.h"

#include "Image/stb_image.h"
#include "glad/glad.h"
#include "LowRenderer/Camera.h"

Model::Model()
{
    VBO = 0;
    VAO = 0;
}

Model::~Model()
{
    if (mesh)
        delete mesh;
}

void Model::Load(const char* modelPath, const char* texturePath)
{
    std::ifstream file;
    file.open(modelPath);
    std::string line;
    std::vector<Vector3> positions;
    std::vector<Vector3> normals;
    std::vector<Vector2> textureUVs;

    if (!file.is_open())
    {
        Log::Print("Cannot open the file: %s", modelPath);
        return;
    }

    while (!file.eof())
    {
        std::getline(file, line);
        if (line[0] == 'v' && line[1] == 't')
        {
            Vector2 vt;
            sscanf_s(line.c_str(), "vt %f %f", &vt.x, &vt.y);
            textureUVs.push_back(vt);
        }
        else if (line[0] == 'v' && line[1] == 'n')
        {
            Vector3 vn;
            sscanf_s(line.c_str(), "vn %f %f %f", &vn.x, &vn.y, &vn.z);
            normals.push_back(vn);
        }
        else if (line[0] == 'v')
        {
            Vector3 v;
            sscanf_s(line.c_str(), "v %f %f %f", &v.x, &v.y, &v.z);
            positions.push_back(v);
        }
        else if (line[0] == 'f')
        {
            Vertex v1;
            Vertex v2;
            Vertex v3;
            int i1[3];
            int i2[3];
            int i3[3];
            sscanf_s(line.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d", &i1[0], &i1[1], &i1[2], &i2[0], &i2[1], &i2[2], &i3[0], &i3[1], &i3[2]);
            v1.Position = positions[i1[0]-1];
            v1.TextureUV = textureUVs[i1[1]-1];
            v1.Normal = normals[i1[2]-1];
            v2.Position = positions[i2[0]-1];
            v2.TextureUV = textureUVs[i2[1]-1];
            v2.Normal = normals[i2[2]-1];
            v3.Position = positions[i3[0]-1];
            v3.TextureUV = textureUVs[i3[1]-1];
            v3.Normal = normals[i3[2]-1];
            vertices.push_back(v1);
            vertices.push_back(v2);
            vertices.push_back(v3);
        }
    }
    Log::Print("Succeed to load model: %s", modelPath);
}


