#pragma once
#include "../IAudioEngine.h"
#include "Speaker.h"
#include "Listener.h"
#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alext.h>
#include <AL/efx.h>
#include <AL/efx-creative.h>
#include <AL/efx-presets.h>

namespace s_Audio
{
    class ALAudio : public IAudioEngine
    {
    private:
        ALCdevice *dev;
        ALCcontext *context;
        Listener listener;
        static const int NUM_BUFFERS = 256;
        ALCuint buffers[NUM_BUFFERS];
        bool used_buffers[NUM_BUFFERS];

    public:
        Speaker createSpeaker() override;
        void destroySpeaker(Speaker speaker) override;
        void setListener(Listener listener) override;
        void update() override;
        void setListenerProps(Listener* props);
        bool initAudio() override;
        bool destroyAudio() override;
    };
}