#pragma once

#include "Core.h"

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

		
		~Video();
	};

}