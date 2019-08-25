#pragma once

#ifdef OE_PLATFORM_WINDOWS

	extern OE::Application* OE::createApplication();
	OE::Video* s_Video = OE::Video::getInstance();
	OE::Input* s_Input = OE::Input::getInstance();

	int main(int argc, char* argv[])
	{
		OE::Log::init();
		s_Video->init();

		int a = 4;

		OE_CORE_WARN("Initialized Log!");
		OE_INFO("Hello Var={0}", a);

		OE::Application* app = OE::createApplication();
		app->run();
		delete app;

		return 0;
	}
#endif // OE_PLATFORM_WINDOWS
