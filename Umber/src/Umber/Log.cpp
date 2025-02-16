#include "umpch.h"

#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Umber
{
    std::shared_ptr<spdlog::logger> Log::SCoreLogger;
    std::shared_ptr<spdlog::logger> Log::SClientLogger;
    
    void Log::Init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        SCoreLogger = spdlog::stdout_color_mt("UMBER");
        SCoreLogger->set_level(spdlog::level::trace);
        
        SClientLogger = spdlog::stdout_color_mt("APP");
        SClientLogger->set_level(spdlog::level::trace);
    }
}
