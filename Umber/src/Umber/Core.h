#pragma once

#ifdef UM_PLATFORM_WINDOWS
	#ifdef UM_BUILD_DLL
		#define UMBER_API __declspec(dllexport)
	#else
		#define UMBER_API __declspec(dllimport)
	#endif
#else
	#error Umber only supports Windows!
#endif

#define BIT(x) (1 << x)

#ifdef UM_ENABLE_ASSERTS
	#define UM_ASSERT(x, ...) { if(!(x)) { UM_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define UM_CORE_ASSERT(x, ...) { if(!(x)) { UM_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define UM_ASSERT(x, ...)
	#define UM_CORE_ASSERT(x, ...)
#endif