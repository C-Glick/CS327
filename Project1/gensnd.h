#ifndef GENSND_INCLUDED
    #define GENSND_INCLUDED
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include "sound.h"
   
    Sound* genDTMF(char key, float sampleRate, float duration);
    Sound* genSilence(float sampleRate, float duration);
    Sound* gensine(float hertz, float sampleRate, float duration);
    Sound* genSquare(float hertz, float sampleRate, float duration);
    Sound* genTriangle(float hertz, float sampleRate, float duration);
    Sound* genSawtooth(float hertz, float sampleRate, float duration);
#endif