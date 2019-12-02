#include <iostream>
#include <Owl.h>
#include "Camera.h"

/**
*@class Sandbox
* @brief Applicacion de prueba para probar las funcionalidades del motor.
*/
class Sandbox : public OE::Application
{
private:
	
	OE::Mesh* mesh;
	OE::Shader* shader;
	Camera* mainCamera;
	OE::Transform obj;

public:
	Sandbox() 
	{
		

		OE::Log::init();

		OE_CORE_INFO("El motor se esta iniciando!");

		s_Video->init();

		mesh = new OE::Mesh();
		mesh->createQuad();

		shader = new OE::Shader();
		shader->init("Shader");		

		mainCamera = new Camera();
		mainCamera->init(Ortho);
		mainCamera->getTransform()->setPosition({ 0.0f, 0.0f, 3.0f });

		obj.setPosition({ 400.0f, 300.0f, -4.0f });
		obj.setScale({ 100.0f, 100.0f, 0.0f });
		
	}

	~Sandbox()
	{
		delete mesh;
		delete mainCamera;
		delete shader;
		
	}

	/**
	* Ciclo de vida de la aplicación.
	*/
	void run()
	{		
		while (!s_Input->getExit())
		{
			s_Input->update();
			s_Video->draw(mesh->getVAO(), mesh->getVertexsIndex()->size(), shader, obj.getTransform(), mainCamera->getView(), mainCamera->getProjection());
		}
	}
};

OE::Application* OE::createApplication()
{
	return new Sandbox();
}