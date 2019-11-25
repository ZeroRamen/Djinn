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

#ifdef DJINN_ENABLE_ASSERTS
	#define DJINN_ASSERT(x, ...) { if(!x)) { Djinn_Error("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define DJINN_CORE_ASSERT(x, ...) { if(!x)) { Djinn_Core_Error("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define DJINN_ASSERT(x, ...)
	#define DJINN_CORE_ASSERT(x, ...)
#endif

// bit flag macro
// Enables bitwise operators (70-80% faster than comparison operators)
#define BIT(x) (1 << x)

// Macro to bind functions to events
#define DJINN_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)