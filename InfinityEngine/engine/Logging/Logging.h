#pragma once

#include <base/typedef.h>
#include <time.h>

namespace Debug {
	void LogInfo(const char *message);
	void LogWarning(const char *message);
	void LogError(const char *message);
}