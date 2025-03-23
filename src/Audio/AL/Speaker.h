#pragma once
#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alext.h>
#include <AL/efx.h>
#include <AL/efx-creative.h>
#include <AL/efx-presets.h>
namespace s_Audio
{
    struct Speaker
    {
        ALuint source;
        ALuint buffer;
        uint ID;

        void load(ALenum format, ALvoid* data, ALsizei size, ALsizei freq){
            alBufferData(buffer, format, data, size, freq);
            if (alGetError() != AL_NO_ERROR)
            {
                logger::log(logger::LEVEL_ERROR, "Failed to load audio from data!");
            }
        }
        void stop(){
            alSourceStop(source);
        }
        void play(){
            alSourcePlay(source);
        }
        void pause(){
            alSourcePause(source);
        }
        void seek(float sec){
            alSourcef(source, AL_SEC_OFFSET, sec);
        }
        float getTime(){
            float offset;
            alGetSourcef(source, AL_SEC_OFFSET, &offset);
            return offset;
        }
        
        //literally everything here
    };
    
} // namespace s_Audio
