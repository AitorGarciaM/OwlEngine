#include "oepch.h"
#include "Video.h"

vector3 cameraFront = {0.0f, 0.0f, -1.0f};
vector3 cameraPosition = { 0.0f ,0.0f, 5.0f };

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

		window = SDL_CreateWindow("Owl Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

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

	void Video::draw(unsigned int _VAO, unsigned int _indexSize, Shader* _shader, mat4 _transform, mat4 _view, mat4 _projection)
	{
		glClear(GL_COLOR_BUFFER_BIT);

		//mat4 proj = mat4(1);
		//proj = glm::ortho(0.0f, (float)WINDOW_WIDTH , (float)WINDOW_HEIGHT, 0.0f, 0.1f, 100.0f);
		////proj = glm::perspective(glm::radians(40.0f), (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 0.1f, 100.0f);
		//mat4 view = mat4(1);
		//view = glm::lookAt(cameraPosition, vector3(0.0f,0.0f,0.0f) , vector3UP);

		//mat4 trasnform = mat4(1);
		//trasnform = glm::translate(trasnform, vector3((float)WINDOW_WIDTH/2, (float)WINDOW_HEIGHT/2, 4.0f));
		//trasnform = glm::scale(trasnform, vector3(100.0f, 100.0f, 100.0f));

		_shader->use();

		glUniformMatrix4fv(glGetUniformLocation(_shader->getProgramId(), "transform"), 1, GL_FALSE, glm::value_ptr(_transform));
		glUniformMatrix4fv(glGetUniformLocation(_shader->getProgramId(), "projection"), 1, GL_FALSE, glm::value_ptr(_projection));
		glUniformMatrix4fv(glGetUniformLocation(_shader->getProgramId(), "view"), 1, GL_FALSE, glm::value_ptr(_view));

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