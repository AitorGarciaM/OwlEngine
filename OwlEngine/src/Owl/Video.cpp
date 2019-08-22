#include "oepch.h"
#include "Video.h"

namespace OE {

	Video* Video::instance = NULL;

	Video::Video()
	{
	}

	Video * Video::getInstance()
	{
		if (instance == NULL)
		{
			instance = new Video();
		}

		return instance;
	}

	void Video::init()
	{
		window = SDL_CreateWindow("Owl Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	}


	Video::~Video()
	{
	}

}