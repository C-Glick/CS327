#include "process.h"

//mix the given sounds together, the volume array holds the magnitude
//of each sound to be mixed.
//numSounds is the number of sounds provided to this function
//sounds and volume should be the same length
//all sounds passed in should be the same sample rate
Sound* mix(Sound* sounds[], float volume[], int numSounds){
    //check sample rates
    float sampleRate = sounds[0]->rate;
    for(int i = 1; i < numSounds; i++){
        if(sounds[i]->rate != sampleRate){
            //exit if different sample rates
            fprintf(stderr, "mixing error: sounds passed in are not the same sample rate.");
            return NULL;
        }
    }

    float numSamples = sounds[0]->length;
    //find longest sound
    for(int i = 1; i < numSounds; i++){
        numSamples = (sounds[i]->length > numSamples) ? sounds[i]->length : numSamples;
    }

    Sound* mixResult = malloc(sizeof(Sound));
    mixResult->rate = sampleRate;
    mixResult->length = numSamples;
    mixResult->samples = malloc(sizeof(float) * mixResult->length);

    //start mixing
    for(int sample = 0; sample < numSamples; sample++){
        mixResult->samples[sample] = 0;
        
        for(int soundNum = 0; soundNum < numSounds; soundNum++){
            Sound* sound = sounds[soundNum];
            if(sound->length > sample){
                mixResult->samples[sample] += sound->samples[sample] * volume[soundNum];
            }
        }
    }

    return mixResult;

}

//uses the amplitude of s1 to control the amplitude of s2
//s1 and s2 must be the same length
Sound* modulate(Sound* s1, Sound* s2){
    //check length
    if(s1->length != s2->length){
        return NULL;
    }

    Sound* result = malloc(sizeof(Sound));
    result->rate = s1->rate;
    result->length = s1->length;
    result->samples = malloc(sizeof(float) * result->length);

    for(int i=0; i < result->length; i++){
        //multiply the two samples together and saves it into the result
        *(result->samples + i) = *(s1->samples + i) * *(s2->samples + i);
    }

    return result;
}

//s is the sound to be filtered, 
//fir is the filter definition array,
//c is the number of elements in fir
//returns a pointer to the filtered sound
Sound* filter(Sound* s, float fir[], int c){
    Sound* result = malloc(sizeof(Sound));
    result->rate = s->rate;
    result->length = s->length;
    result->samples = malloc(sizeof(float) * result->length);

    for(int i=0; i < result->length; i++){
        *(result->samples + i) = 0;
        for(int j=0; j < c; j++){
            if(i - j < 0){continue;}
            *(result->samples + i) += *(s->samples + (i-j)) * fir[j];
        }
    }

    return result;
}

//provide some reverb to the sound provided
//delay is the time between the original sound and the reverb
//delay must be between 0 (inclusive) and 0.1 (inclusive) seconds
//attenuation is the volume of the reverb,
//attenuation of 1 is full volume, 0 is none
Sound* reverb(Sound* s, float delay, float attenuation){
    //check inputs
    if(delay < 0 || delay > 0.1){
        fprintf(stderr, "reverb error: %f is not a valid reverb delay, must be between 0 (inclusive) and 0.1 (inclusive) seconds.", delay);
        return NULL;
    }
    if(attenuation < 0 || attenuation > 1){
        fprintf(stderr, "reverb error: %f is not a valid attenuation, must be between 0 (inclusive) and 1 (inclusive).", attenuation);
        return NULL;
    }
    if(s == NULL){
        fprintf(stderr, "reverb error: Sound passed in is NULL.");
        return NULL;
    }

    int c = (int) (delay * s->rate) + 1;

    float fir[c];

    fir[0] = 1;
    for(int i = 1; i < c-1; i++){
        fir[i] = 0;
    }
    if(c>1){
        fir[c-1] = attenuation;
    }
    return filter(s, fir, c);
}

//the same as reverb but
//delay must be between 0.1 (exclusive) and 1 (inclusive) second
Sound* echo(Sound* s, float delay, float attenuation){
    //check inputs
    if(delay <= 0.1 || delay > 1){
        fprintf(stderr, "echo error: %f is not a valid echo delay, must be between 0.1 (exclusive) and 1 (inclusive) second.", delay);
        return NULL;
    }
    if(attenuation < 0 || attenuation > 1){
        fprintf(stderr, "echo error: %f is not a valid attenuation, must be between 0 (inclusive) and 1 (inclusive).", attenuation);
        return NULL;
    }
    if(s == NULL){
        fprintf(stderr, "echo error: Sound passed in is NULL.");
        return NULL;
    }

    int c = (int) (delay * s->rate) + 1;

    float fir[c];

    fir[0] = 1;
    for(int i = 1; i < c-1; i++){
        fir[i] = 0;
    }
    if(c>1){
        fir[c-1] = attenuation;
    }
    return filter(s, fir, c);
}
