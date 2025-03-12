#pragma once
#include <GameObject.h>
#include "src/Renderer/IRenderEngine.h"
#include <Scriptables/Transform.h>

namespace sparks
{
    class Camera : public GameObject{
        public:
        s_Renderer::Cam cam;
        Camera():GameObject(){
            
            addScriptable(new Transform());
            cam.dir = &getScriptable<Transform>()->rotation;
            cam.pos = &getScriptable<Transform>()->position;
            cam.far = 100.0f;
            cam.near = 0.1f;
            cam.fov = 90;

        
        }
    };
} // namespace sparks
