#include <base/typedef.h>
#include <time.h>
#include "Logging.h"

void Debug::LogInfo(const char *message) {
	std::cout << "\033[1;0mINFO:    [" << time(0) << "] - " << message << std::endl;
}

void Debug::LogWarning(const char *message) {
	std::cout << "\033[1;33mWARNING: [" << time(0) << "] - " << message << "\033[1;0m" << std::endl;
}

void Debug::LogError(const char *message) {
	std::cout << "\033[1;31mError:   [" << time(0) << "] - " << message << "\033[1;0m" << std::endl;
}