#include <Scriptables/AudioSource.h>
namespace sparks
{

    AudioSource::AudioSource()
    {
        
    }
    AudioSource::~AudioSource(){
        Context::getContext()->removeSpeaker(speaker);
    }
    void AudioSource::Stop(){

    }
    void AudioSource::Load(std::string file){

    }
    void AudioSource::onStart(){
        speaker = Context::getContext()->getSpeaker();
    }
    void AudioSource::onTick(){

    }
    void AudioSource::Pause(){

    }
    void AudioSource::Play(){

    }
    void AudioSource::Seek(float sec){

    }


    
} // namespace sparks
