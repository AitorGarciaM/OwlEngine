#pragma once

#include "Core.h"
#include "Shader.h"

#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 800

namespace OE {
	/**
	*@class Video
	*@brief nos permite crear una pantalla y dibujar en ella, ademas inicializa OpenGL y SDL2.
	*/
	class OWL_API Video
	{
	private:
		static Video* instance;

		SDL_Window* window;
		SDL_GLContext context;

		Video();
	public:

		/**
		* Nos devuelbe la instancia de la clase.
		*/
		static Video* getInstance();
		/**
		* Inicializa los sistemas.
		*/
		void init();

		/**
		* dibuja en pantalla.
		*/
		void draw(unsigned int _VAO, unsigned int _indexSize ,Shader* _shader, mat4 _transform, mat4 _view, mat4 _projection);

		
		~Video();
	};

}