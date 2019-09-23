#pragma once

#include "Core.h"
#include "Shader.h"

#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 800

namespace OE {

	class OWL_API Video
	{
	private:
		static Video* instance;

		SDL_Window* window;
		SDL_GLContext context;

		Video();
	public:
		static Video* getInstance();
		void init();

		void draw(unsigned int _VAO, unsigned int _indexSize ,Shader* _shader, mat4 _transform, mat4 _view, mat4 _projection);

		
		~Video();
	};

}