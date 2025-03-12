#include <Game.h>
#include <Scene.h>

class someGame : sparks::Game {

    void update() override;
    void onMouseMove(double x, double y) override;
    void onKeyPress(sparks::Keys key);
    void onKeyRelease(sparks::Keys key);
    void init() override;
    
};

