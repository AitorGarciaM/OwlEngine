#pragma once

#include "Core.h"

namespace OE {

	class OWL_API Shader
	{
	private:
		GLuint idProgram;
		bool _allOk;
	public:
		Shader();
		~Shader();

		void init(const GLchar* filename);
		GLuint getProgramId() { return idProgram; };
		void use() { if (_allOk) glUseProgram(idProgram); }
		void deleteProgram() { if (_allOk) glDeleteProgram(idProgram); }

		void stopShader() { if (_allOk) { glUseProgram(0); } }

	};

}