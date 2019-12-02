#pragma once

#include "Core.h"

namespace OE {
	/**
	* @class Shader
	* @brief Compila los shader en grafica.
	*/
	class OWL_API Shader
	{
	private:
		GLuint idProgram;
		bool _allOk;
	public:
		Shader();
		~Shader();
		/**
		* Carga y compila el shader.
		*/
		void init(const GLchar* filename);

		/**
		* Nos devuelbe la ID del shader.
		*/
		GLuint getProgramId() { return idProgram; };
		/**
		* Ejecuta el shader en la grafica.
		*/
		void use() { if (_allOk) glUseProgram(idProgram); }
		/**
		* borra el shader de la GRAM.
		*/
		void deleteProgram() { if (_allOk) glDeleteProgram(idProgram); }
		/**
		* Detiene el shader en la grafica.
		*/
		void stopShader() { if (_allOk) { glUseProgram(0); } }

	};

}