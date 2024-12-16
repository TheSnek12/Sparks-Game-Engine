#include "Logger.h"

namespace logger
{
    
    _levelSettings::_levelSettings():
    enabled(true), output(std::clog)    
    {
    }

    void setEnabled(Level level, bool enabled){

    }
    bool setLevelStream(Level level, std::ostream stream){

    }
    void log(Level level, const char* str){

    }
}