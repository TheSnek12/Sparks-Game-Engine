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
        this->speaker.stop();
    }
    void AudioSource::Load(std::string file){
        
        audiofile.load(file);
        std::vector<uint8_t> pcmData_uint8;
        audiofile.savePCMToBuffer(pcmData_uint8);

        this->speaker.load(AL_FORMAT_STEREO8, pcmData_uint8.data(), sizeof(uint8_t)*pcmData_uint8.size(), audiofile.getSampleRate()*2);
    }
    void AudioSource::onStart(){
        speaker = Context::getContext()->getSpeaker();
    }
    void AudioSource::onTick(){
        
    }
    void AudioSource::Pause(){
        this->speaker.pause();
    }
    void AudioSource::Play(){
        Transform *transform = object->getScriptable<Transform>();
        
        this->speaker.play(transform->position);
    }
    void AudioSource::Seek(float sec){
        this->speaker.seek(sec);

    }


    
} // namespace sparks
