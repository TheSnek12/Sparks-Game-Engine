#pragma once
#include "src/Base.h"
#include "src/Context.h"


// singleton class representing the currently running game.
namespace sparks
{

    class Context;
    class Game
    {
    private:
        /* data */
        inline static Game *_instance = nullptr;
        const char * _name = "Untitled";
        void handleClose();
        void handleAbort();
        uint16_t _width = 800;
        uint16_t _height = 800;

    public:
        
        u_int16_t getWidth();
        u_int16_t getHeight();

        static Game *getInstance();
        bool run();
        void frame();
        const char * getName();
        Game(/* args */);
        ~Game();
    protected:    
        virtual void update();
        virtual void init();
        void close();
        void abort();
        void setGeometry(uint16_t w, uint16_t h);
        void setName(const char * name);


    };
}
