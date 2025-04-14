#pragma once



namespace sparks
{
    enum PACKET_TYPE{
        FIELDS,
        CALLABLES,
        FIELD_UPDATE,
        CALL
    };
    enum TYPE_DEFINITONS{
        INT,
        UINT,
        LONG,
        LONG_LONG,
        SHORT,
        ULONG,
        ULONG_LONG,
        USHORT,
        FLOAT,
        DOUBLE,
        VEC2,
        VEC3,
        VOID
        
    };

    struct Field{
        const char* name;
        TYPE_DEFINITONS type;
        const char* data;

    };
    struct Callable{
        const char* name;
        TYPE_DEFINITONS type;

    };


    struct Packet
    {
        PACKET_TYPE type;
        const char* data;    
    };


    struct Name{
        const char* name;
        char seperation_byte = 255; 
    };
    struct DefinitionsPacket
    {
        Name *fields;
        TYPE_DEFINITONS type;
    };
    struct FieldUpdatePacket
    {
        Name field;
        const char* val;
    };
    struct CallPacket{
        Name callable;
        bool expectReturn;
    };
    
    
    
} // namespace sparks
