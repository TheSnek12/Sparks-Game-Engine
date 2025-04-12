#include "Scriptable.h"
#include "src/Audio/AL/ALAudio.h"
#include "src/Context.h"
#include "src/ThirdParty/audiofile/AudioFile.h"



namespace sparks
{
    
    class AudioSource : public Scriptable
    {
    private:
        s_Audio::Speaker speaker;
        AudioFile<double> audiofile;
        
        
    public:
        AudioSource(/* args */);
        ~AudioSource();
        void onStart() override;
        void onTick() override;
        void Load(std::string file);
        void Play();
        void Pitch(float pitch);
        void Pause();
        void Stop();
        void Seek(float timestamp);
    };

} // namespace sparks

