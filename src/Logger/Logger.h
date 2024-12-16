#include <iostream>
#include <cstdio>
namespace logger{



    enum Level {
        LEVEL_LOG = 0,
        LEVEL_WARN = 1,
        LEVEL_ERROR = 2,
        LEVEL_FATAL = 3
    };
    static _levelSettings _logLevels[4];
    
    struct _levelSettings
    {
        bool enabled;
        std::ostream &output;
        _levelSettings();
    };

    void log(Level level, const char* str);

    void setEnabled(Level level, bool enabled);

    bool setLevelStream(Level level, std::ostream stream);







};

