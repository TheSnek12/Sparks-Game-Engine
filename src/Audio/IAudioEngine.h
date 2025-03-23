#pragma once
#include "Audio.h"
#include "AL/Speaker.h"
#include "AL/Listener.h"
namespace s_Audio
{
    class IAudioEngine{
        public:
        virtual Speaker createSpeaker() = 0;
        virtual void destroySpeaker(Speaker speaker) = 0;
        virtual bool initAudio() = 0;
        virtual bool destroyAudio() = 0;
        virtual void update() = 0;
        virtual void setListener(Listener listener) = 0;
        

    };
} // namespace s_Audio
