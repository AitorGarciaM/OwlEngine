#pragma once

#include "Core.h"
#include "Shader.h"

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

		void draw(unsigned int _VAO, Shader* _shader);

		
		~Video();
	};

}