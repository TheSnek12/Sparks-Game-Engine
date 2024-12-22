#ifndef HGAME
#define HGAME

#include "src/Base.h"
#include "src/Context.h"
// singleton class representing the currently running game.
namespace sparks
{
    class Game
    {
    private:
        /* data */
        inline static Game *_instance = nullptr;
        const char * _name;
        void handleClose();
        void handleAbort();
        u_int16_t _width;
        u_int16_t _height;

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
        void setGeometry(u_int16_t w, u_int16_t h);
        void setName(const char * name);


    };
}
#endif
