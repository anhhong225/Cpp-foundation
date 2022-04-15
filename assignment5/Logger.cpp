#include <ctime>
#include <iostream>
#include <iomanip>
#include "Logger.h"


std::string logFileName(){
    auto time = std::time(nullptr);
    char buffer[100];
    std::strftime(buffer, sizeof(buffer), "Log_%H_%M_%S.txt", std::localtime(&time));
    return std::string{buffer};
}


Logger::Logger(): m_out{logFileName().c_str()}{}

Logger &Logger::get() {
    static Logger instance{};
    return instance;
}

void Logger::log(std::string msg) {
    if(m_out.is_open()){
        m_out.write(msg).newline();
    }
    else{
        std::cerr << "Logger::log: log file not open\n";
    }
}
