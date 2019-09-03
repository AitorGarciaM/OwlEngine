#include "oepch.h"

#include "Mesh.h"

namespace OE {

	void Mesh::createMesh()
	{
		glGenBuffers(1, &EBO);

		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, vertexs.size() * sizeof(Vertex), &vertexs[0],GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, vertexIndex.size() * sizeof(unsigned int), &vertexIndex[0], GL_STATIC_DRAW);

		// Loads vertex positions.
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

		// Loads normals.
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normals));

		// Loads texture coordinates.
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uvs));

		glEnableVertexAttribArray(0);
	}

	void Mesh::loadMesh(std::string _filename)
	{

		std::string path = "./Resources/" + _filename;
		std::fstream meshHandler;

		std::vector<vector3> tempPositions, tempNormals;
		std::vector<vector2> tempUvs;

		meshHandler.open(path, std::fstream::in);

		if (meshHandler.is_open())
		{
			while (!meshHandler.eof())
			{
				std::string tempLine;
				std::getline(meshHandler, tempLine);

				std::string tipoValor = tempLine.substr(0, tempLine.find(" "));

				if (tipoValor == "v")
				{
					int space = 1, space2;
					vector3 tempVec3;

					for (int i = 0; i < 3; i++)
					{

						space2 = tempLine.find((char)32, space + 1);

						int size = space2 - space;

						std::string val = tempLine.substr(space + 1, size);

						space = space2;

						if (i == 0)
						{
							tempVec3.x = std::stof(val);
						}
						else if (i == 1)
						{
							tempVec3.y = std::stof(val);
						}
						else if (i == 2)
						{
							tempVec3.z = std::stof(val);
						}
					}

					tempPositions.push_back(tempVec3);
				}
				else if (tipoValor == "f")
				{
					int space = 1, space2;

					unsigned int indexPositions;
					unsigned int indexUvs;
					unsigned int indexNormals;

					for (int i = 0; i < 3; i++)
					{
						space2 = tempLine.find(" ", space + 1);

						int size = space2 - space;

						std::string values = tempLine.substr(space + 1, size);

						space = space2;

						int slash = 0, slash2;

						for (int j = 0; j < 3; j++)
						{
							slash2 = values.find("/", slash + 1);

							int size = slash2 - slash;

							std::string valueF = values.substr(slash, size);

							slash = slash2 + 1;

							if (j == 0)
							{
								float a = std::stof(valueF);
								indexPositions = a - 1;
								vertexIndex.push_back(indexPositions);
								/*std::cout << "position value: " << indexPositions << std::endl;*/
							}
							else if (j == 1)
							{
								float a = std::stof(valueF);
								indexUvs = a - 1;
								uvIndex.push_back(indexUvs);
							}
							else if (j == 2)
							{
								float a = std::stof(valueF);
								indexNormals = a - 1;
								normalIndex.push_back(indexNormals);
							}
						}
					}
				}
				else if (tipoValor == "vt")
				{
					int space = 2, space2;
					vector2 tempVector;

					for (int i = 0; i < 2; i++)
					{
						space2 = tempLine.find(" ", space + 1);

						int size = space2 - space;

						std::string values = tempLine.substr(space, size);

						space = space2;

						if (i == 0)
						{
							tempVector.x = std::stof(values);
						}
						if (i == 1)
						{
							tempVector.y = std::stof(values);
						}
					}

					tempUvs.push_back(tempVector);
				}
				else if (tipoValor == "vn")
				{
					int space = 2, space2;
					vector3 tempVec3;

					for (int i = 0; i < 3; i++)
					{

						space2 = tempLine.find((char)32, space + 1);

						int size = space2 - space;

						std::string val = tempLine.substr(space + 1, size);

						space = space2;

						if (i == 0)
						{
							tempVec3.x = std::stof(val);
						}
						else if (i == 1)
						{
							tempVec3.y = std::stof(val);
						}
						else if (i == 2)
						{
							tempVec3.z = std::stof(val);
						}
					}

					tempNormals.push_back(tempVec3);
				}
				else
				{
					continue;
				}
			}

			for (int i = 0; i < tempPositions.size(); i++)
			{
				Vertex tempVertex;

				tempVertex.positions = tempPositions[i];
				tempVertex.uvs = tempUvs[i];
				tempVertex.normals = tempNormals[i];

				vertexs.push_back(tempVertex);
			}

			createMesh();
		}
	}

	void Mesh::createQuad()
	{
		vertexs = {
			Vertex{vector3{-0.5f,-0.5f,0.0f},	vector3{0,0,1},		vector2{0.0f,0.0f}},
			Vertex{vector3{0.5f,-0.5f,0.0f},	vector3{0,0,1},		vector2{1.0f,0.0f}},
			Vertex{vector3{-0.5f,0.5f,0.0f},	vector3{0,0,1},		vector2{0.0f,1.0f}},
			Vertex{vector3{0.5f,0.5f,0.0f},		vector3{0,0,1},		vector2{1.0f,1.0f}},
		};

		vertexIndex = {
			0,1,2,
			1,3,2
		};

		normalIndex = {
			1,3,2,
			1,2,0
		};

		uvIndex = {
			0,1,2,
			0,2,3
		};

		createMesh();
	}

	Mesh::Mesh()
	{
	}


	Mesh::~Mesh()
	{
	}

}