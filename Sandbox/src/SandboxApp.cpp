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

		OE::Log::init();
		s_Video->init();

		int a = 4;

		OE_CORE_WARN("Initialized Log!");
		OE_INFO("Hello Var={0}", a);

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