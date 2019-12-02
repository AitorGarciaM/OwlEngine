#pragma once
#include"Core.h"


/**
*Vertex
*@brief Almacena la información de un vertice.
*/
struct Vertex
{

	vector3 positions; //!< posición del vertice.
	vector3 normals; //!< cordenadas de las normales del vertice.
	vector2 uvs; //!< cordenadas de textura del vertice.
};

namespace OE {

	/**
	*@class Mesh
	*@brief Genera mayas a partir de un archivo obj o crea Quads.
	*/
	class OWL_API Mesh
	{
	private:
		std::vector<unsigned int> vertexIndex, uvIndex, normalIndex;
		std::vector<Vertex> vertexs;

		unsigned int VAO, VBO, EBO;

		/**
		* Crea una maya.
		*/
		void createMesh();
	public:

		/**
		* Carga un archivo obj y extrae los valores.
		*/
		void loadMesh(std::string _filename);

		/**
		* Crea un Quad.
		*/
		void createQuad();

		/**
		* Nos devuelbe los indices de las posiciones de la maya.
		*/
		std::vector<unsigned int>* getVertexsIndex() { return &vertexIndex; }
		/**
		* Nos debuelve los indices de las coordenadas de textura.
		*/
		std::vector<unsigned int>* getUvsIndex() { return &uvIndex; }
		/**
		* Nos devuelbe los indices de las coordenadas de la normal.
		*/
		std::vector<unsigned int>* getNormalsIndex() { return &normalIndex; }
		/**
		* Nos devuelbe los vertices de la textura.
		*/
		std::vector<Vertex>* getVertexs() { return &vertexs; }
		/**
		* Nos devuelbe el VAO de la maya.
		*/
		unsigned int getVAO() { return VAO; }

		Mesh();
		~Mesh();
	};

}
