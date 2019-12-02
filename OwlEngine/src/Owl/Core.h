#pragma once

#ifdef OE_PLATFORM_WINDOWS
	#ifdef OE_BUILD_DLL
		#define OWL_API __declspec(dllexport)
	#else
		#define OWL_API __declspec(dllimport)
	#endif
#else
	#error OwlEngine only suports Windows!
#endif // HZ_PLATFORM_WINDOWS

#define mat4 glm::mat4
#define vector2 glm::vec2
#define vector3 glm::vec3

const glm::vec3 up = { 0.0f,1.0f,0.0f };

#define vector3UP up

