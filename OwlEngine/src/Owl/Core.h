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

