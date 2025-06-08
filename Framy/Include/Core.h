#pragma once

#include "Log.h"

#define BIT(x) (1 << x)

#ifdef BUILD_DEBUG
    #define FR_ASSERT(x, ...) { if(!(x)) { LOG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
    #define CORE_ASSERT(x, ...) { if(!(x)) { CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
    #define FR_ASSERT(x, ...)
    #define CORE_ASSERT(x, ...)
#endif