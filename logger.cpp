#ifndef LOGGER_IMPL
#define LOGGER_IMPL

#include "logger.h"

void Logger::operator << (std::stringstream msg) {
    std::cout << msg.str() << std::endl;
    fflush(stdout);
}

#endif // LOGGER_IMPL
