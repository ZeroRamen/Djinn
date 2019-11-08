#pragma once

#ifdef DJINN_PLATFORM_WINDOWS
	#ifdef DJINN_BUILD_DLL
		#define DJINN_API _declspec(dllexport)
	#else
		#define DJINN_API _declspec(dllimport)
	#endif
#else
	#error Djinn only supports Windows!
#endif