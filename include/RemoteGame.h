#pragma once
#include <enet/enet.h>
#include "src/Networking/Networking.h"
#include <vector>
#include <future>
#include <algorithm>
#include <Logger/Logger.h>
#include <cstring>
namespace sparks
{
    enum CONNECTION_STATE{
        NOT_ATTEMPTED,
        CONNECTED,
        FAILED,
        DISCONNECTED,
    };
    class RemoteGame{
        public:
        const int TIMEOUT_MILLISECONDS = 5000;
        RemoteGame(const char* address, uint port);
        ~RemoteGame();
        CONNECTION_STATE getState(){
            return state;
        }

        int getIntField(const char * name);
        float getFloatField(const char * name);
        private:
        std::vector<Field> remoteFields;
        std::vector<Callable> remoteCalls;
        bool threadClosing = false;
        CONNECTION_STATE state = NOT_ATTEMPTED;
        bool attemptConnect();
        void deserialize(const char* data, size_t len);
        void startClient();
        std::future<void> clientThread;
        ENetAddress remoteAddress;
        ENetEvent event;
        ENetPeer* remote;
        ENetHost* client;
    };

} // namespace sparks
