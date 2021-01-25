#ifndef PROCESS_INCLUDED
    #define PROCESS_INCLUDED
    #include "sound.h"
    #include <stdlib.h>
    #include <stdio.h>

    Sound* mix(Sound* sounds[], float volume[], int numSounds);
    Sound* modulate(Sound* s1, Sound* s2);
    Sound* filter(Sound* s, float fir[], int c);
    Sound* reverb(Sound* s, float delay, float attenuation);
    Sound* echo(Sound* s, float delay, float attenuation);


#endif