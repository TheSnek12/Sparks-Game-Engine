#include "Test.h"

someGame game = someGame();
sparks::Scene scene;
sparks::GameObject obj;





void someGame::update()
{

}

void someGame::init(){
    
    scene.addObject(&obj);

    setGeometry(500, 500);
    setName("Sparks Game Engine Test");
    loadScene(&scene);
}