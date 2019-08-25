#include <iostream>
#include <Owl.h>



class Sandbox : public OE::Application
{
public:
	Sandbox() 
	{
	}
	~Sandbox()
	{
	}

	void run()
	{
		std::cout << "Welcome to OwlEngine!" << std::endl;	
		while (!s_Input->getExit())
		{
			s_Input->update();
		}
	}
};

OE::Application* OE::createApplication()
{
	return new Sandbox();
}