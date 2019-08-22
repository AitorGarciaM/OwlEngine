#pragma once
#include <SDL.h>
#include "Core.h"

namespace OE {

	class OWL_API Video
	{
	private:
		static Video* instance;

		SDL_Window* window;
		SDL_Renderer* renderer;

		Video();
	public:
		static Video* getInstance();
		void init();
		~Video();
	};

}