#include <iostream>
#include <Owl.h>



class Sandbox : public OE::Application
{
private:
	
	OE::Mesh* mesh;
	OE::Shader* shader;
public:
	Sandbox() 
	{
		OE::Log::init();
		s_Video->init();

		mesh = new OE::Mesh();
		mesh->loadMesh("Quad.obj");

		shader = new OE::Shader();
		shader->init("Shader");
		
	}
	~Sandbox()
	{
	}

	void run()
	{		
		while (!s_Input->getExit())
		{
			s_Input->update();
			s_Video->draw(mesh->getVAO(), mesh->getVertexsIndex()->size(), shader);
		}
	}
};

OE::Application* OE::createApplication()
{
	return new Sandbox();
}