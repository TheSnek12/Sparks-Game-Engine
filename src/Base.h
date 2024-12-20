#ifndef HBASE
#define HBASE
#include <cassert>
#include <iostream>
#include <chrono>
#include <fstream>
#include <cstdio>

namespace sparks
{
#define LOG(s) std::clog << "[" << std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count() << "]: " << s << std::endl;
}

#endif