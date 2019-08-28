#include <iostream>
#include <Owl.h>



class Sandbox : public OE::Application
{
private:
	unsigned int VAO, VBO, EBO;

	OE::Shader* shader;
public:
	Sandbox() 
	{
		OE::Log::init();
		s_Video->init();

		shader = new OE::Shader();
		shader->init("Shader");
		
	}
	~Sandbox()
	{
	}

	void run()
	{
		float vertex[] =
		{
			0.0f,  1.0f, 0.0f,
			0.5f,  0.0f, 0.0f,
			1.0f, -1.0f, 0.0f,
			0.0f, -1.0f, 0.0f,
		   -0.5f,  0.0f, 0.0f,
		   -1.0f, -1.0f, 0.0f
		};

		unsigned int indices[] =
		{
			0, 1, 4,
			1, 2, 3,
			3, 4, 5
		};

		glGenBuffers(1, &EBO);		
				
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);

		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		while (!s_Input->getExit())
		{
			s_Input->update();
			s_Video->draw(VAO, shader);
		}
	}
};

OE::Application* OE::createApplication()
{
	return new Sandbox();
}