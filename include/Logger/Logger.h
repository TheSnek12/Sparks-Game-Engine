#pragma once

#include <iostream>
#include <cstdio>
#include <chrono>
#include <fstream>

namespace logger{



    enum Level {
        LEVEL_LOG = 0,
        LEVEL_WARN = 1,
        LEVEL_ERROR = 2,
        LEVEL_FATAL = 3
    };

    struct _levelSettings
    {
        bool enabled;
        void (*callback) (Level, const char*);
        _levelSettings();
    };

    static _levelSettings _logLevels[4];

    void log(Level level, const char* str);

    void setEnabled(Level level, bool enabled);

    void setCallback(Level level, void (*callback) (Level, const char*));

};