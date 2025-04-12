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
            alSourceStop(source);
            alSourcei(source, AL_BUFFER, 0);
            alBufferData(buffer, format, data, size, freq);
            //so the value is viewable in the debugger
            ALenum e = alGetError();
            if (e != AL_NO_ERROR)
            {
                logger::log(logger::LEVEL_ERROR, "Failed to load audio from data!");
            }
            alSourcei(source, AL_BUFFER, buffer);
        }
        void stop(){
            alSourceStop(source);
        }
        void play(Vec3 pos){
            alSource3f(source, AL_POSITION, pos.x, pos.y, pos.z);
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
        void pitch(float pitch){
            alSourcef(source, AL_PITCH, pitch);
        }
        
        //literally everything here
    };
    
} // namespace s_Audio
