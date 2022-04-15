#ifndef ASSIGNMENT5_LOGGER_H
#define ASSIGNMENT5_LOGGER_H

#include "FileWriter.h"

class Logger{
public:
    static Logger& get();
    void log(std::string msg);

private:
    // private, default constructor
    Logger();
    FileWriter m_out;
};


#endif //ASSIGNMENT5_LOGGER_H
