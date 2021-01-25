#include "gensnd.h"


//generates the proper tone for the button pressed
//pass in the character to generate a tone for
//valid chars, 1 2 3 4 5 6 7 8 9 0 a b c d # * 
//returns a pointer to the sound struct
Sound* genDTMF(char key, float sampleRate, float duration){
    float frequency1;
    float frequency2;
    
    //determain frequency1
    switch (key){
        case '1': case '2': case '3' :case 'a': case 'A':
            frequency1 = 697;
            break;
        case '4': case '5': case '6': case 'b': case 'B':
            frequency1 = 770;
            break;
        case '7': case '8': case '9': case 'c': case 'C':
            frequency1 = 852;
            break;
        case '*': case '0': case '#': case 'd': case 'D':
            frequency1 = 941;
            break;
        default:
            exit(1);
    }

    //determain frequency2
    switch (key){
        case '1': case '4': case '7': case '*':
            frequency2 = 1209;
            break;
        case '2': case '5': case '8': case '0':
            frequency2 = 1336;
            break;
        case '3': case '6': case '9': case '#':
            frequency2 = 1477;
            break;
        case 'a': case 'A': case 'b': case 'B': case 'c': case 'C': case 'd': case 'D':
            frequency2 = 1633;
            break;
        default:
            exit(1);
    }

    Sound* tone1 = gensine(frequency1, sampleRate, duration);
    Sound* tone2 = gensine(frequency2, sampleRate, duration);

    Sound* result = malloc(sizeof(Sound));
    result->rate = tone1->rate;
    result->length = tone1->length;
    result->samples = malloc(sizeof(float) * result->length);

    //combine tones
    for(int i = 0; i < tone1->length; i++){
        *(result->samples + i) = (*(tone1->samples + i) + *(tone2->samples + i))/2.0;
    }

    //discard tone1 and tone2
    free(tone1->samples);
    free(tone1);

    free(tone2->samples);
    free(tone2);

    return result;
}

//produces silence (0.0 value) at the sample rate
//and for the length given
//returns a pointer to the sound struct 
Sound* genSilence(float sampleRate, float duration){
    Sound* sound = malloc(sizeof(Sound));
    sound->rate = sampleRate;
    sound->length = duration * sampleRate;
    sound->samples = malloc(sizeof(float) * sound->length);

    for(int currentSample=0; currentSample < sound->length; currentSample++){
        *(sound->samples + currentSample) = 0;
    }
    
    return sound;
}

//generates a sin wave tone with the given paramaters,
//returns a pointer to the sound struct of the resulting sound
Sound* gensine(float hertz, float sampleRate, float duration){
    Sound* sound = malloc(sizeof(Sound));
    sound->rate = sampleRate;
    sound->length = duration * sampleRate;
    sound->samples = malloc(sizeof(float) * sound->length);

    for(int currentSample=0; currentSample < sound->length; currentSample++){
        float value = sin(2 * M_PI * hertz *  currentSample/sampleRate);
        *(sound->samples + currentSample) = value;
    }
    
    return sound;
}

//generates a square wave tone with the given paramaters,
//returns a pointer to the sound struct of the resulting sound
Sound* genSquare(float hertz, float sampleRate, float duration){
    Sound* sound = malloc(sizeof(Sound));
    sound->rate = sampleRate;
    sound->length = duration * sampleRate;
    sound->samples = malloc(sizeof(float) * sound->length);

    for(int currentSample=0; currentSample < sound->length; currentSample++){

        float value = 2 * (2 * floor(hertz * currentSample / sampleRate) - floor(2 * hertz * currentSample / sampleRate)) + 1;
        *(sound->samples + currentSample) = value;
    }
    
    return sound;
}

//generates a triangle wave tone with the given paramaters,
//returns a pointer to the sound struct of the resulting sound
Sound* genTriangle(float hertz, float sampleRate, float duration){
    Sound* sound = malloc(sizeof(Sound));
    sound->rate = sampleRate;
    sound->length = duration * sampleRate;
    sound->samples = malloc(sizeof(float) * sound->length);

    for(int currentSample=0; currentSample < sound->length; currentSample++){
        float value = fabs(fmod(4 * hertz * currentSample / sampleRate, 4) - 2) - 1;
        *(sound->samples + currentSample) = value;
    }
    
    return sound;
}

//generates a triangle wave tone with the given paramaters,
//returns a pointer to the sound struct of the resulting sound
Sound* genSawtooth(float hertz, float sampleRate, float duration){
    Sound* sound = malloc(sizeof(Sound));
    sound->rate = sampleRate;
    sound->length = duration * sampleRate;
    sound->samples = malloc(sizeof(float) * sound->length);

    for(int currentSample=0; currentSample < sound->length; currentSample++){
        float value = 2 * ((hertz * currentSample) / sampleRate - floor((hertz * currentSample) / sampleRate)) - 1;
        *(sound->samples + currentSample) = value;
    }
    
    return sound;
}
