#include "RemoteGame.h"


namespace sparks
{
    RemoteGame::RemoteGame(const char* address, uint port){
        enet_address_set_host(&remoteAddress, address);
        remoteAddress.port = port;
        client = enet_host_create(NULL, 1, 2, 0, 0);
        if (client == NULL){
            logger::log(logger::LEVEL_ERROR, "Failed to create client!");
            return;
        }
        clientThread = std::async(std::launch::async, &RemoteGame::startClient, this);
    }

    void RemoteGame::startClient(){
        if (!attemptConnect()){
            state = FAILED;
            return;
        }
        state = CONNECTED;
        while (!threadClosing){
            enet_host_service(client, &event, 0);
            switch (event.type)
            {
            case ENET_EVENT_TYPE_RECEIVE:
                
                deserialize((const char*)event.packet->data, event.packet->dataLength);
                enet_packet_destroy(event.packet);
                break;
            case ENET_EVENT_TYPE_DISCONNECT:
                state = DISCONNECTED;
                event.peer->data = NULL;
                logger::log(logger::LEVEL_LOG, "Disconnected by host");
                return;
            default:
                break;
            }
        }

    }

    void RemoteGame::deserialize(const char* data, size_t len){

        //try to parse packet, if it errors then throw out the packet
        try
        {

        std::string d;
        d.append(data, len-1);
        char packetType = d[0];
        d.erase(d.begin());
        

        switch ((PACKET_TYPE)packetType)
        {
        case FIELDS:
            {
            
            while (d.size() >= 3 && d.find(255) != -1)
            {
                Field f;

                int nameLen = d.find(255)-1;
                std::string name = d.substr(0, nameLen);


                bool exists = false;
                for (Field knownFields : remoteFields){
                    if (knownFields.name == name){
                        d = d.substr(nameLen, d.size()-nameLen);
                        d.erase(d.begin(), d.begin()+2);
                        exists = true;
                        break;
                    }
                }
                if (exists) continue;



                d = d.substr(nameLen, d.size()-nameLen);

                char fieldType = d[0];
                d.erase(d.begin(), d.begin()+2);

                const std::string::size_type size = name.size();
                char *buffer = new char[size + 1];   //we need extra char for NUL
                memcpy(buffer, name.c_str(), size + 1);
                
                f.name = buffer;
                f.type = (TYPE_DEFINITONS)fieldType;
                remoteFields.push_back(f);
            }
            break;
            }
        case CALLABLES:
            {
            
            while (d.size() > 3 && d.find(255) != -1)
            {
                Callable f;

                int nameLen = d.find(255)-1;
                std::string name = d.substr(0, nameLen);
                bool exists = false;
                d = d.substr(nameLen, d.size()-nameLen);
                for (Callable knownCalls : remoteCalls){
                    if (knownCalls.name == name){
                        d.erase(d.begin(), d.begin()+2);
                        exists = true;
                        break;
                    }
                }
                if (exists) continue;

                char fieldType = d[0];
                d.erase(d.begin(), d.begin()+2);

                const std::string::size_type size = name.size();
                char *buffer = new char[size + 1];   //we need extra char for NUL
                memcpy(buffer, name.c_str(), size + 1);
                
                f.name = buffer;
                f.type = (TYPE_DEFINITONS)fieldType;
                remoteCalls.push_back(f);
            }
            break;
            }
        case FIELD_UPDATE:
            {
                int nameLen = d.find(255);
                std::string name = d.substr(0, nameLen);
                d = d.substr(nameLen, d.size()-nameLen);
                d.erase(d.begin());

                for (int i = 0; i < remoteFields.size(); i++){
                    if (remoteFields[i].name == name){
                        char * buff = new char[d.size()+1];
                        memcpy(buff, d.c_str(), d.size()+1);
                        remoteFields[i].data = buff;
                    }
                }
            }
            break;
        case CALL:
            
            break;

        default:
            break;
        }
        }
        catch(const std::exception& e)
        {
            return;
        }
        
    }

    int RemoteGame::getIntField(const char* name){
        for (Field f : remoteFields){
            if (f.type != INT) continue;
            if (strcmp(f.name, name) == 0){
                return *((int*)f.data);
            }
        }
        return 0;
    }
    float RemoteGame::getFloatField(const char* name){
        for (Field f : remoteFields){
            if (f.type != FLOAT) continue;
            if (strcmp(f.name, name) == 0){
                return *((float*)f.data);
            }
        }
        return 0;
    }
    bool RemoteGame::attemptConnect(){
        remote = enet_host_connect(client, &remoteAddress, 2, 0);
        if (enet_host_service(client, &event, TIMEOUT_MILLISECONDS) > 0 && 
            event.type == ENET_EVENT_TYPE_CONNECT){
            return true;

        }else{
            enet_peer_reset(remote);
            logger::log(logger::LEVEL_ERROR, "Failed to connect to host!");
            return false;
        }
    }
    RemoteGame::~RemoteGame(){
        this->threadClosing = true;
        clientThread.get();
        enet_host_destroy(client);
    }
} // namespace sparks
