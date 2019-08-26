#pragma once

#include "Core.h"

namespace OE {

	class OWL_API Shader
	{
	private:
		GLuint idProgram;
		bool allOk;
	public:
		Shader();
		~Shader();

		void init(const GLchar* filename);
		GLuint getProgramId() { return idProgram; };
		void use() { if (allOk) glUseProgram(idProgram); }
		void deleteProgram() { if (allOk) glDeleteProgram(idProgram); }

	};

}