#ifndef HCONTEXT
#define HCONTEXT
#include "include/Game.h"

namespace sparks{

class Game;
class IContext{
    virtual bool init() = 0;
    virtual bool initWindow() = 0;
    virtual bool initRenderer() = 0;
    virtual bool cleanup() = 0;
    virtual bool destroyWindow() = 0;
    virtual bool destroyRenderer() = 0;
    virtual void pollWindowEvents() = 0;
    virtual void messageLoop() = 0;

    public:
    virtual ~IContext() = default;

    

};
enum GameState{
    PREINIT,
    RUNNING,
    CLOSING,
    ABORTING

};
class Context final : IContext{
    private:

    inline static Context * _instance = nullptr;
    GameState _state;
    //renderer
    //windowing system - based on inheritance

    
    Game *_game;
    GLFWwindow *_window;
    private:
    bool init() override;
    bool cleanup() override;
    void messageLoop() override;
    void pollWindowEvents() override;
    bool initRenderer() override;
    bool initWindow() override;
    bool destroyWindow() override;
    bool destroyRenderer() override;
    //eventually will add methods to handle poll events

    public:
    static Context* getContext();
    void close();
    void abort();

    Context();
    ~Context();



};


} // namespace sparks
#endif