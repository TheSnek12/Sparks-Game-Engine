#pragma once
#include "ALAudio.h"

namespace s_Audio
{
   bool ALAudio::initAudio(){
        dev = alcOpenDevice(NULL);
        if (!dev){
            logger::log(logger::LEVEL_ERROR, "Failed to open audio device!");
            return false;
        }
        context = alcCreateContext(dev, NULL);
        alcMakeContextCurrent(context);

        alGetError();

        alGenBuffers(NUM_BUFFERS, buffers);

        ALenum error = alGetError();
        if (error != AL_NO_ERROR){
            logger::log(logger::LEVEL_ERROR, "Failed to create buffer!");
            return false;
        }
        return true;
        
   }

   Speaker ALAudio::createSpeaker(){
        Speaker speaker;
        for (size_t i = 0; i < NUM_BUFFERS; i++)
        {
            if (!used_buffers[i]){
                speaker.ID = i;
                used_buffers[i] = true;
                break;
            }
        }
        speaker.buffer = buffers[speaker.ID];
        alGenSources(1, &speaker.source);
        return speaker;
   }
   void ALAudio::destroySpeaker(Speaker speaker){
        used_buffers[speaker.ID] = false;
        alDeleteBuffers(1, &speaker.buffer);
        alDeleteSources(1, &speaker.source);
   }

   void ALAudio::setListenerProps(Listener* props){
        alListenerf(AL_GAIN, *props->gain);
        alListener3f(AL_POSITION, props->pos->x, props->pos->y, props->pos->z);
        alListener3f(AL_VELOCITY, props->vel->x, props->vel->y, props->vel->z);
        float orientation[] = {props->dir->x, props->dir->y, props->dir->z, props->up->x, props->up->y, props->up->z};
        alListenerfv(AL_ORIENTATION, orientation);
    }

   
    void ALAudio::setListener(Listener listener){
        this->listener = listener;
    }

    void ALAudio::update(){
        setListenerProps(&listener);
    }

    bool ALAudio::destroyAudio(){
        context=alcGetCurrentContext();
        dev=alcGetContextsDevice(context);
        alcMakeContextCurrent(NULL);
        alcDestroyContext(context);
        alcCloseDevice(dev);
        return true;
   }
} // namespace s_Audio
