#include "log.h"

Logger::Logger(const std::string &logfilepath, const std::string level) : logfile(logfilepath), ofs(logfilepath, std::ios::app), level_(level), buffer("")
{
    if (fileExists(logfile))
    {
        return;
    }
    else
    {
        std::ofstream logFile(logfile);
        if (!logFile)
        {
            std::cerr << "Create logger.log failed!" << std::endl;
            return;
        }
        logFile.close();
        // Change logfile's permission to anyone can read or write
        if (chmod(logfile.c_str(), S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH) != 0)
        {
            std::cerr << "Change logfile's permission failed!" << std::endl;
            return;
        }
    }
}

bool Logger::fileExists(const std::string &filename)
{
    std::ifstream file(filename);
    return file.good();
}

std::string Logger::getCurTime()
{
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

Logger::~Logger()
{
    if (ofs.is_open())
    {
        std::cout << getCurTime() << "  " << level_ << buffer.str() << std::endl;
        ofs << getCurTime() << "    " << level_ << buffer.str() << std::endl;
        ofs.close();
    }
}