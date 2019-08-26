#pragma once

#ifdef OE_PLATFORM_WINDOWS

	extern OE::Application* OE::createApplication();
	OE::Video* s_Video = OE::Video::getInstance();
	OE::Input* s_Input = OE::Input::getInstance();

	int main(int argc, char* argv[])
	{
		OE::Application* app = OE::createApplication();
		app->run();
		delete app;

		return 0;
	}
#endif // OE_PLATFORM_WINDOWS
