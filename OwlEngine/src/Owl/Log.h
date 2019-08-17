#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace OE {

	class OWL_API Log
	{
	private:
		static std::shared_ptr<spdlog::logger> sCoreLogger;
		static std::shared_ptr<spdlog::logger> sClientLogger;
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return sCoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return sClientLogger; }
	};

}

// Core Log macros.
#define OE_CORE_FATAL(...)		::OE::Log::getCoreLogger()->fatal(__VA_ARGS__)
#define OE_CORE_ERROR(...)		::OE::Log::getCoreLogger()->error(__VA_ARGS__)
#define OE_CORE_WARN(...)		::OE::Log::getCoreLogger()->warn(__VA_ARGS__)
#define OE_CORE_INFO(...)		::OE::Log::getCoreLogger()->info(__VA_ARGS__)
#define OE_CORE_TRACE(...)		::OE::Log::getCoreLogger()->trace(__VA_ARGS__)

// Client Log macros.
#define OE_FATAL(...)   ::OE::Log::getCoreLogger()->fatal(__VA_ARGS__)
#define OE_ERROR(...)   ::OE::Log::getCoreLogger()->error(__VA_ARGS__)
#define OE_WARN(...)    ::OE::Log::getCoreLogger()->warn(__VA_ARGS__)
#define OE_INFO(...)    ::OE::Log::getCoreLogger()->info(__VA_ARGS__)
#define OE_TRACE(...)   ::OE::Log::getCoreLogger()->trace(__VA_ARGS__)
