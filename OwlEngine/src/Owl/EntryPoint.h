#pragma once

#ifdef OE_PLATFORM_WINDOWS

	extern OE::Application* OE::createApplication();
	
	int main(int argc, char* argv[])
	{
		OE::Application* app = OE::createApplication();
		app->run();
		delete app;
	}
#endif // OE_PLATFORM_WINDOWS
