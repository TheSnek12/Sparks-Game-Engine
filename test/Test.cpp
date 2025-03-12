#include "Test.h"
#include <Scriptables/Transform.h>
#include <Scriptables/RenderMesh.h>
#include <Camera.h>
#include <math.h>

someGame game = someGame();
sparks::Scene* scene = new sparks::Scene();
sparks::GameObject* obj = new sparks::GameObject();
sparks::Transform* script = new sparks::Transform();
sparks::RenderMesh* objRender = new sparks::RenderMesh();



sparks::Camera cam;

double xrot = 0;
double yrot = 0;
bool wPressed = false;
bool aPressed = false;
bool sPressed = false;
bool dPressed = false;

float toRads(float n){
    return n * (M_PI/180);
}

void someGame::update()
{
    obj->getScriptable<sparks::Transform>()->position += 0.01f;
    //static_cast<sparks::Transform*>(cam.scriptables[0])->position.z += 0.01;
    if (wPressed){
        Vec3 dir = cam.getScriptable<sparks::Transform>()->rotation * 0.1;
        cam.getScriptable<sparks::Transform>()->position += dir;
    }
    if (aPressed){
        Vec3 dir = cam.getScriptable<sparks::Transform>()->rotation.cross(Vec3(0.0f, 1.0f, 0.0f)) * 0.1;
        cam.getScriptable<sparks::Transform>()->position -= dir;
    }
    if (sPressed){
        Vec3 dir = cam.getScriptable<sparks::Transform>()->rotation * 0.1;
        cam.getScriptable<sparks::Transform>()->position -= dir;
    }
    if (dPressed){
        Vec3 dir = cam.getScriptable<sparks::Transform>()->rotation.cross(Vec3(0.0f, 1.0f, 0.0f)) * 0.1;
        cam.getScriptable<sparks::Transform>()->position += dir;
    }
}

void someGame::onKeyPress(sparks::Keys key){
    if (key == sparks::W){
        wPressed = true;
    }

    if (key == sparks::A){
        aPressed = true;
    }

    if (key == sparks::S){
        sPressed = true;
    }

    if (key == sparks::D){
        dPressed = true;
    }

}
void someGame::onKeyRelease(sparks::Keys key){
    if (key == sparks::W){
        wPressed = false;
    }

    if (key == sparks::A){
        aPressed = false;
    }

    if (key == sparks::S){
        sPressed = false;
    }

    if (key == sparks::D){
        dPressed = false;
    }
}

double pitch = 0;
double yaw = 0;

void someGame::onMouseMove(double x, double y){
    yaw += x * 0.5;
    pitch += y * 0.5;

    pitch = std::min(89.9, pitch);
    pitch = std::max(-89.9, pitch);

    cam.getScriptable<sparks::Transform>()->rotation.x = cos(toRads(yaw)) * cos(toRads(pitch));
    cam.getScriptable<sparks::Transform>()->rotation.y = sin(toRads(pitch));
    cam.getScriptable<sparks::Transform>()->rotation.z = sin(toRads(yaw)) * cos(toRads(pitch));

    cam.getScriptable<sparks::Transform>();




}

void someGame::init(){
    
    scene->addObject(obj);
    obj->addScriptable(script);
    objRender->object = obj;
    obj->addScriptable(objRender);
    scene->activeCamera = &cam;

    obj->getScriptable<sparks::Transform>()->rotation = Vec3(1.0f, 1.0f, 0.0f);
    obj->getScriptable<sparks::Transform>()->position = Vec3(1.0f, 0.5f, 0.0f);
    cam.getScriptable<sparks::Transform>()->rotation = Vec3(1.0f, 0.0f, 0.0f);
    cam.getScriptable<sparks::Transform>()->position = Vec3(1.0f, 0.5f, 0.0f);


    setName("Sparks Game Engine Test");
    loadScene(scene);
}