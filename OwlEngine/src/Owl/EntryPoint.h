#pragma once

#ifdef OE_PLATFORM_WINDOWS

	extern OE::Application* OE::createApplication();
	
	int main(int argc, char* argv[])
	{
		OE::Log::init();
		int a = 4;

		OE_CORE_WARN("Initialized Log!");
		OE_INFO("Hello Var={0}", a);

		OE::Application* app = OE::createApplication();
		app->run();
		delete app;
	}
#endif // OE_PLATFORM_WINDOWS
