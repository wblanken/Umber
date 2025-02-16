#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Umber
{
    class UMBER_API Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return SCoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return SClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> SCoreLogger;
        static std::shared_ptr<spdlog::logger> SClientLogger;
    };
}

// Core log macros
#define UM_CORE_TRACE(...) ::Umber::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define UM_CORE_INFO(...)  ::Umber::Log::GetCoreLogger()->info(__VA_ARGS__)
#define UM_CORE_WARN(...)  ::Umber::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define UM_CORE_ERROR(...) ::Umber::Log::GetCoreLogger()->error(__VA_ARGS__)
#define UM_CORE_FATAL(...) ::Umber::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define UM_TRACE(...)      ::Umber::Log::GetClientLogger()->trace(__VA_ARGS__)
#define UM_INFO(...)       ::Umber::Log::GetClientLogger()->info(__VA_ARGS__)
#define UM_WARN(...)       ::Umber::Log::GetClientLogger()->warn(__VA_ARGS__)
#define UM_ERROR(...)      ::Umber::Log::GetClientLogger()->error(__VA_ARGS__)
#define UM_FATAL(...)      ::Umber::Log::GetClientLogger()->fatal(__VA_ARGS__)