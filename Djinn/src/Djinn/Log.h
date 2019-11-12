#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Djinn
{
	class DJINN_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core logging macros
#define Djinn_Core_Error(...)	::Djinn::Log::GetCoreLogger()->error(__VA_ARGS__)
#define Djinn_Core_Warn(...)	::Djinn::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define Djinn_Core_Info(...)	::Djinn::Log::GetCoreLogger()->info(__VA_ARGS__)
#define Djinn_Core_Trace(...)	::Djinn::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define Djinn_Core_Fatal(...)	::Djinn::Log::GetCoreLogger()->fatal(__VA_ARGS__)


// Client logging macros
#define Djinn_Error(...)	::Djinn::Log::GetClientLogger()->error(__VA_ARGS__)
#define Djinn_Warn(...)		::Djinn::Log::GetClientLogger()->warn(__VA_ARGS__)
#define Djinn_Info(...)		::Djinn::Log::GetClientLogger()->info(__VA_ARGS__)
#define Djinn_Trace(...)	::Djinn::Log::GetClientLogger()->trace(__VA_ARGS__)
#define Djinn_Fatal(...)	::Djinn::Log::GetClientLogger()->fatal(__VA_ARGS__)

// if dist build
#define Djinn_Core_Info