#include "Test.h"
#include <Scriptables/Transform.h>
#include <Scriptables/RenderMesh.h>
#include <Scriptables/AudioSource.h>
#include <Scriptables/DirectionalLight.h>
#include <Scriptables/PointLight.h>
#include <Camera.h>
#include <GameHost.h>
#include <RemoteGame.h>
#include <math.h>

someGame game = someGame();
sparks::Scene* scene = new sparks::Scene();
sparks::GameObject* obj = new sparks::GameObject();
sparks::Transform* script = new sparks::Transform();
sparks::RenderMesh* objRender = new sparks::RenderMesh("test/res/obj/cube.obj");
sparks::AudioSource* audio = new sparks::AudioSource();


sparks::GameObject* testcube = new sparks::GameObject();
sparks::Transform* transform = new sparks::Transform();
sparks::RenderMesh* renderer = new sparks::RenderMesh("test/res/obj/cube.obj");

sparks::GameObject* lightObj = new sparks::GameObject();
sparks::Transform* lightTransform = new sparks::Transform();
sparks::DirectionalLight* lightSource = new sparks::DirectionalLight();
sparks::PointLight* lightSource2 = new sparks::PointLight();

sparks::GameHost host(23001);
sparks::RemoteGame remote("127.0.0.1", 23000);

sparks::Camera* cam = new sparks::Camera();


double xrot = 0;
double yrot = 0;
bool wPressed = false;
bool aPressed = false;
bool sPressed = false;
bool dPressed = false;

float x;
float y;
float z;


float toRads(float n){
    return n * (M_PI/180);
}

double t = 0;
void someGame::update()
{
    x = cam->getScriptable<sparks::Transform>()->position.x;
    y = cam->getScriptable<sparks::Transform>()->position.y;
    z = cam->getScriptable<sparks::Transform>()->position.z;
    if (remote.getState() == sparks::CONNECTED){

        testcube->getScriptable<sparks::Transform>()->position.x =- x;
        std::cout << remote.getFloatField("y") << std::endl;
        testcube->getScriptable<sparks::Transform>()->position.y =- y;
        testcube->getScriptable<sparks::Transform>()->position.z =- z;


    }
    t += 0.01;
    lightObj->getScriptable<sparks::Transform>()->rotation.x = sin(t);
    lightObj->getScriptable<sparks::Transform>()->rotation.z = cos(t);

    //static_cast<sparks::Transform*>(cam.scriptables[0])->position.z += 0.01;
    if (wPressed){
        Vec3 dir = cam->getScriptable<sparks::Transform>()->rotation * 0.1;
        cam->getScriptable<sparks::Transform>()->position += dir;
    }
    if (aPressed){
        Vec3 dir = cam->getScriptable<sparks::Transform>()->rotation.cross(Vec3(0.0f, 1.0f, 0.0f)).normalize() * 0.1;
        cam->getScriptable<sparks::Transform>()->position -= dir;
    }
    if (sPressed){
        Vec3 dir = cam->getScriptable<sparks::Transform>()->rotation * 0.1;
        cam->getScriptable<sparks::Transform>()->position -= dir;
    }
    if (dPressed){
        Vec3 dir = cam->getScriptable<sparks::Transform>()->rotation.cross(Vec3(0.0f, 1.0f, 0.0f)).normalize() * 0.1;
        cam->getScriptable<sparks::Transform>()->position += dir;
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

    if (key == sparks::I){
        audio->Load("test/res/sounds/melee_frying_pan_01.wav");
        cam->volumeGain = 200;
        audio->Play();
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

    cam->getScriptable<sparks::Transform>()->rotation.x = cos(toRads(yaw)) * cos(toRads(pitch));
    cam->getScriptable<sparks::Transform>()->rotation.y = sin(toRads(pitch));
    cam->getScriptable<sparks::Transform>()->rotation.z = sin(toRads(yaw)) * cos(toRads(pitch));

    cam->getScriptable<sparks::Transform>();




}


void someGame::init(){
    host.registerField(sparks::FLOAT, "x", &x);
    host.registerField(sparks::FLOAT, "y", &y);
    host.registerField(sparks::FLOAT, "z",  &z);

    scene->addObject(lightObj);
    lightObj->addScriptable(lightTransform);
    lightObj->addScriptable(lightSource);
    //lightObj->addScriptable(lightSource2);
    lightObj->getScriptable<sparks::Transform>()->position = Vec3(0, 1, 0);
    lightObj->getScriptable<sparks::Transform>()->rotation = Vec3(0, -1, 0);

    scene->addObject(obj);
    obj->addScriptable(script);
    obj->addScriptable(objRender);
    obj->addScriptable(audio);

    scene->addObject(testcube);
    testcube->addScriptable(transform);
    testcube->addScriptable(renderer);
    
    scene->addObject(cam);
    scene->activeCamera = cam;


    obj->getScriptable<sparks::Transform>()->rotation = Vec3(1.0f, 0.0f, 0.0f);
    obj->getScriptable<sparks::Transform>()->position = Vec3(5.0f, 0.0f, 0.0f);
    obj->getScriptable<sparks::Transform>()->scale = Vec3(1, 1, 1);
    obj->getScriptable<sparks::RenderMesh>()->addTexture("test/res/textures/texture-paint-white-background-gouache-canvas-stripes-98611292.jpg");

    testcube->getScriptable<sparks::Transform>()->position = Vec3(0, 0 ,0);
    testcube->getScriptable<sparks::Transform>()->rotation = Vec3(0, 0, -1);
    testcube->getScriptable<sparks::Transform>()->scale = Vec3(0.2, 0.2, 0.2);

    cam->getScriptable<sparks::Transform>()->rotation = Vec3(1.0f, 0.0f, 0.0f);
    cam->getScriptable<sparks::Transform>()->position = Vec3(0.1f, 0.0f, 0.0f);


    setName("Sparks Game Engine Test");
    loadScene(scene);
}   
