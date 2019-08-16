#pragma once
#include "Core.h"

namespace OE {

	class OWL_API Application
	{
	public:

		virtual void run() = 0;

		Application();
		virtual ~Application();
	};

	// this must be defined in CLIENT.
	Application* createApplication();

}
