#pragma once

#include <spdlog/spdlog.h>

namespace Framy {
    class Log 
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
} // Framy

#ifdef BUILD_DEBUG
    #define CORE_TRACE(...)  ::Framy::Log::GetCoreLogger()->trace(__VA_ARGS__)
    #define CORE_INFO(...)   ::Framy::Log::GetCoreLogger()->info(__VA_ARGS__)
    #define CORE_WARN(...)   ::Framy::Log::GetCoreLogger()->warn(__VA_ARGS__)
    #define CORE_ERROR(...)  ::Framy::Log::GetCoreLogger()->error(__VA_ARGS__)
    #define CORE_FATAL(...)  ::Framy::Log::GetCoreLogger()->critical(__VA_ARGS__)

    #define LOG_TRACE(...)   ::Framy::Log::GetClientLogger()->trace(__VA_ARGS__)
    #define LOG_INFO(...)    ::Framy::Log::GetClientLogger()->info(__VA_ARGS__)
    #define LOG_WARN(...)    ::Framy::Log::GetClientLogger()->warn(__VA_ARGS__)
    #define LOG_ERROR(...)   ::Framy::Log::GetClientLogger()->error(__VA_ARGS__)
    #define LOG_FATAL(...)   ::Framy::Log::GetClientLogger()->critical(__VA_ARGS__)
#else
    #define CORE_TRACE
    #define CORE_INFO
    #define CORE_WARN
    #define CORE_ERROR
    #define CORE_FATAL

    #define LOG_TRACE
    #define LOG_INFO
    #define LOG_WARN
    #define LOG_ERROR
    #define LOG_FATAL
#endif