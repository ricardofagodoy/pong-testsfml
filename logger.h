#ifndef LOGGER
#define LOGGER

#include <iostream>
#include <sstream>

class Logger {
    Logger() {}
    Logger(Logger const&);
    void operator=(Logger const&);
public:
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }
    void operator << (std::stringstream msg);
};

#endif // LOGGER

