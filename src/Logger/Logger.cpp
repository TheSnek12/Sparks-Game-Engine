#include <Logger/Logger.h>

namespace logger
{
    
    _levelSettings::_levelSettings():
    enabled(true), callback(NULL)    
    {
    }



    void setCallback(Level level, void (*callback) (Level, const char*)){
        _logLevels[level].callback = callback;
    }

    void setEnabled(Level level, bool enabled){
        _logLevels[level].enabled = enabled;

    }


    void log(Level level, const char* str){

        if (!_logLevels[level].enabled) return;
            if (_logLevels[level].callback){
                _logLevels[level].callback(level, str);
            return;
        }
        
        
        std::ofstream out("log.txt", std::ios::app);
        out << "[" << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << "] ";     
        switch (level)
        {
        case LEVEL_LOG:
            out << "[LOG] ";
            break;
        case LEVEL_WARN:
            out << "[WARN] ";
            break;
        case LEVEL_ERROR:
            out << "[ERROR] ";
            break;
        case LEVEL_FATAL:
            out << "[FATAL] ";
            break;
        default:
            break;
        }
        out << str << std::endl; 
    }
}