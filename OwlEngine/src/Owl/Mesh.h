#pragma once
#include"Core.h"

struct Vertex
{
	vector3 positions, normals;
	vector2 uvs;
};

namespace OE {
	class OWL_API Mesh
	{
	private:
		std::vector<unsigned int> vertexIndex, uvIndex, normalIndex;
		std::vector<Vertex> vertexs;

		unsigned int VAO, VBO, EBO;

		void createMesh();
	public:
		void loadMesh(std::string _filename);

		void createQuad();

		std::vector<unsigned int>* getVertexsIndex() { return &vertexIndex; }
		std::vector<unsigned int>* getUvsIndex() { return &uvIndex; }
		std::vector<unsigned int>* getNormalsIndex() { return &normalIndex; }
		std::vector<Vertex>* getVertexs() { return &vertexs; }

		unsigned int getVAO() { return VAO; }

		Mesh();
		~Mesh();
	};

}
