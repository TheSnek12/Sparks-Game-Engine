#pragma once
#include "src/Networking/Networking.h"
#include "src/Base.h"
#include <future>
#include <enet/enet.h>
#include <vector>
#include <string>
namespace sparks
{

    typedef void (*callable_func)();
    struct Field_ptr
    {
        const char* name;
        TYPE_DEFINITONS type;
        void* ptr;
    };
    struct Callable_ptr
    {
        const char* name;
        callable_func func;
    };
    
    class GameHost{
        public:
        GameHost(unsigned int port);
        ~GameHost();
        void registerCallable(const char* name, callable_func call);
        void registerField(TYPE_DEFINITONS type, const char* name, void* ptr);
        void informClient(ENetPeer * peer);
        void updateValues(ENetPeer *peer);
        private:
        bool threadClosing = false;
        ENetAddress address;
        ENetHost *server;
        std::future<void> hostThread;
        std::vector<Callable_ptr> callables;
        std::vector<Field_ptr> fields;
        void startHost();
        const char* serialize();
        

    };
} // namespace sparks
