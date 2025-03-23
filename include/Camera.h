#pragma once
#include <GameObject.h>
#include "src/Renderer/IRenderEngine.h"
#include "src/Audio/IAudioEngine.h"
#include <Scriptables/Transform.h>
#include <Vec3.h>

namespace sparks
{
    class Camera : public GameObject{
        public:
        s_Renderer::Cam cam;
        s_Audio::Listener listener;

        Vec3 zero;
        float volumeGain = 0;
        Camera():GameObject(){
            
            addScriptable(new Transform());
            cam.dir = &getScriptable<Transform>()->rotation;
            cam.pos = &getScriptable<Transform>()->position;
            cam.far = 10000.0f;
            cam.near = 0.1f;
            cam.fov = 90;

            listener.dir = &getScriptable<Transform>()->rotation;
            listener.pos = &getScriptable<Transform>()->position;
            listener.up = &getScriptable<Transform>()->up;
            listener.gain = &volumeGain;
            listener.vel = &zero;

        
        }
    };
} // namespace sparks
