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
		SDL_Init(SDL_INIT_VIDEO);

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

		window = SDL_CreateWindow("Owl Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

		context = SDL_GL_CreateContext(window);

		glewExperimental = GL_TRUE;
		GLenum glewError = glewInit();

		if (glewError != GLEW_OK)
		{
			std::cout << "Error initializing GLEW! " << "\n" << glewGetErrorString(glewError) << std::endl;

			system("Pause");

			return;
		}

		SDL_GL_SetSwapInterval(1);

		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	}

	void Video::draw(unsigned int _VAO, unsigned int _indexSize ,Shader* _shader)
	{
		glClear(GL_COLOR_BUFFER_BIT);

		_shader->use();

		glBindVertexArray(_VAO);
		glDrawElements(GL_TRIANGLES, _indexSize, GL_UNSIGNED_INT, 0);

		glBindVertexArray(0);

		_shader->stopShader();

		SDL_GL_SwapWindow(window);

	}


	


	Video::~Video()
	{
	}

}