#pragma once
#include "Core.h"

namespace OE {

	/**
	 * @class Application
	 * @brief Es una clase virtual que permite ejecutar desde el entry point cualquier applicación que herede de esta.
	 */
	class OWL_API Application
	{
	public:

		/**
		* ejecuta la applicacion.
		*/
		virtual void run() = 0;

		Application();
		virtual ~Application();
	};

	/**
	* Esta funcion crea la applicacion. Se programa desde fuera.
	*/
	// this must be defined in CLIENT.
	Application* createApplication();

}
