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