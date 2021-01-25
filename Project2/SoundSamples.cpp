#include "SoundSamples.h"
#include <iostream>
/** default constructor */
SoundSamples::SoundSamples(){
    rate = 8000;
    length = 0;
}
/** specific constructor */
SoundSamples::SoundSamples(float* samples, int length, float rate){
    this->rate = rate;
    this->length = length;
    this->samples = new float[length];
    for(int i = 0; i < length; i++){
        this->samples[i] = samples[i];
    }
}
SoundSamples::SoundSamples(int length, int rate){
    this->length = length;
    this->rate = rate;
    samples = new float[length];
    for(int i = 0; i < length; i++){
        samples[i] = 0;
    }
}
/** copy constructor*/
SoundSamples::SoundSamples(const SoundSamples& toCopy){
    rate = toCopy.rate;
    length = toCopy.length;

    samples = new float[length];
    //deep copy
    for(int i = 0; i < length; i++){
        samples[i] = toCopy.samples[i];
    }
}

//inplace reverb
void SoundSamples::reverb2(float delay, float attenuation){
    if(delay < 0 || attenuation < 0){
        std::cerr << "Reverb error: invalid parameters, delay and attenuation must be greater than or equal to 0.";
        return;
    }
    int sampleDelay = (int)(delay * rate);

    for(int i=0; i<length; i++){
        if(i-sampleDelay < 0){
            //do nothing
        } else{
            samples[i] += samples[i-sampleDelay]*attenuation;
        }
    }
}

void SoundSamples::asdr(float atime, float alevel, float dtime, float slevel, float rtime){
    if(atime < 0 || dtime < 0 || rtime < 0){
        std::cerr << "ASDR error: invalid parameters, time values must be greater than or equal to 0.";
        return;
    }else if((atime + dtime + rtime) * rate > length){
        std::cerr << "ASDR error: invalid parameters, the sum of the time values must be less than or equal to the duration of the sound.";
        return;
    }

    float duration = length / rate;

    for(int i=0; i<length; i++){
        float time = i/rate;
        //attack
        if(time < atime){
            samples[i] *= alevel / atime * time; 
        }
        //decay
        else if(time < atime + dtime){
            samples[i] *= (slevel - alevel) / dtime * (time - atime) + alevel;
        }
        //release
        else if(time > duration - rtime){
            samples[i] *= -slevel / rtime * (time - (duration - rtime)) + slevel;
        }
        //sustain
        else{
            samples[i] *= slevel;
        }
    }
}
