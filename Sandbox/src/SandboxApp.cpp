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
		std::cin.get();
	}
};

OE::Application* OE::createApplication()
{
	return new Sandbox();
}