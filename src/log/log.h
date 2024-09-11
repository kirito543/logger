#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <sstream>
#include <chrono>
#include <iomanip>

#define SINFO Logger("./logger.log", "[INFO]: ")
#define SERROR Logger("./logger.log", "[ERROR]: ")

class Logger
{
public:
    Logger(const std::string &logfilepath, const std::string level);
    bool fileExists(const std::string& filename);
    std::string getCurTime();

    virtual ~Logger();

    template<typename T>
    Logger& operator<<(const T& message)
    {
        
        buffer << message;
        return *this;
    }

    Logger& operator<<(std::ostream& (*func)(std::ostream&))
    {
        buffer << func;
        return *this;
    }

private:
    std::string logfile;
    std::ofstream ofs;
    std::ostringstream buffer;
    std::string level_;
};



