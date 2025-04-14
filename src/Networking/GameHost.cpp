#include <GameHost.h>

namespace sparks
{
    GameHost::GameHost(unsigned int port)
    {
        address.host = ENET_HOST_ANY;
        address.port = port;
        server = enet_host_create(&address, 32, 2, 0, 0);
        if (server == NULL)
        {
            logger::log(logger::LEVEL_ERROR, "Failed to start server!");
            return;
        }
        hostThread = std::async(std::launch::async, &GameHost::startHost, this);
    }
    void GameHost::startHost()
    {
        ENetEvent event;
        while (!threadClosing)
        {
            enet_host_service(server, &event, 0);
            switch (event.type)
            {
            case ENET_EVENT_TYPE_CONNECT:
                /* code */

                informClient(event.peer);
                break;
            case ENET_EVENT_TYPE_DISCONNECT:
                event.peer->data = NULL;

                break;
            case ENET_EVENT_TYPE_NONE:

                break;
            case ENET_EVENT_TYPE_RECEIVE:
                enet_packet_destroy(event.packet);
                break;

            default:
                break;
            }

            updateValues(NULL);
        }
    }

    void GameHost::updateValues(ENetPeer *peer)
    {
        for (Field_ptr f : fields)
        {
            // make this better, i've literally got 4 hours left

            std::string fieldData;
            char packetType = (char)FIELD_UPDATE;
            fieldData += packetType;
            fieldData.append(f.name);
            fieldData.push_back(255);

            int fl = *((float*)f.ptr);

            switch (f.type)
            {
            case INT:
                fieldData.append(static_cast<char *>(f.ptr), sizeof(int));
                break;
            case UINT:
                break;
            case LONG:
                break;
            case LONG_LONG:
                break;
            case SHORT:
                break;
            case ULONG:
                break;
            case ULONG_LONG:
                break;
            case USHORT:
                break;
            case FLOAT:
                fieldData.append(static_cast<char *>(f.ptr), sizeof(float));
                break;
            case DOUBLE:
                break;
            case VEC2:
                break;
            case VEC3:
                break;

            default:
                break;
            }
            ENetPacket *packet = enet_packet_create(fieldData.c_str(), fieldData.size() + 1, ENET_PACKET_FLAG_RELIABLE);
            if (peer != NULL)
                enet_peer_send(peer, 0, packet);
            else
            enet_host_broadcast(server, 0, packet);
        }
    }

    void GameHost::informClient(ENetPeer *peer)
    {
        std::string fieldData;

        char packetType = (char)FIELDS;
        fieldData += packetType;
        for (Field_ptr f : fields)
        {
            fieldData.append(f.name);
            fieldData.push_back((char)f.type);
            fieldData.push_back((char)255);
        }
        ENetPacket *packet = enet_packet_create(fieldData.c_str(), fieldData.size() + 1, ENET_PACKET_FLAG_RELIABLE);
        if (peer != NULL)
            enet_peer_send(peer, 0, packet);
        else
        enet_host_broadcast(server, 0, packet);

        fieldData = "";
        packetType = (char)CALLABLES;
        fieldData += packetType;
        for (Callable_ptr call : callables)
        {
            fieldData.append(call.name);
            fieldData.push_back((char)VOID);
            fieldData.push_back((char)255);
        }

        packet = enet_packet_create(fieldData.c_str(), fieldData.size() + 1, ENET_PACKET_FLAG_RELIABLE);
        if (peer != NULL)
            enet_peer_send(peer, 0, packet);
        else
        enet_host_broadcast(server, 0, packet);
    }

    void GameHost::registerCallable(const char *name, callable_func call)
    {
        Callable_ptr callable;
        callable.name = name;
        callable.func = call;

        callables.push_back(callable);
        informClient(NULL);
    }
    void GameHost::registerField(TYPE_DEFINITONS type, const char *name, void *ptr)
    {
        Field_ptr field;
        field.type = type;
        field.name = name;
        field.ptr = ptr;
        fields.push_back(field);
        informClient(NULL);
    }

    GameHost::~GameHost()
    {
        threadClosing = true;
        hostThread.get();
        enet_host_destroy(server);
    }
} // namespace sparks
