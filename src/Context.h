#include "include/Game.h"

namespace sparks{
class IContext{
    virtual bool init();
    virtual bool initWindow();
    virtual bool initRenderer();
    virtual bool destroyWindow();
    virtual bool destoryRenderer();
    
    virtual void messageLoop();

    virtual ~IContext();
};

class Context : IContext{
    private:
    //renderer
    //windowing system - based on inheritance
    u_int16_t _width;
    u_int16_t _height;
    Game _game;
    bool initWindow();
    void pollWindowEvents();
    bool initRenderer();
    bool destroyWindow();
    bool destroyRenderer();
    bool init();
    void messageLoop();

    public:
    Context();
    ~Context();



};

} // namespace sparks
