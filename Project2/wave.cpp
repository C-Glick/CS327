#include "wave.h"

SoundSamples* Wave::generateSamples(float frequency, float sampleRate, float duration){
    this->frequency = frequency;
    SoundSamples* sound = new SoundSamples((int)(duration * sampleRate), sampleRate);

    for(int sample = 0; sample < sound->getLength(); sample++){
        (*sound)[sample] = generateFunction(sample / sampleRate);
    }
    return sound;
}
