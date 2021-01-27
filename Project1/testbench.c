#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "gensnd.h"
#include "iosnd.h"
#include "process.h"
#include "DLL.h"

int main(){
    Sound* sound = malloc(sizeof(Sound));
    sound->rate = 60;
    sound->length = 16;
    sound->samples = malloc(sizeof(float) * sound->length);
    sound->samples[0] = 0.4;
    sound->samples[1] = 0.1;
    sound->samples[2] = 0;
    sound->samples[3] = 0;
    sound->samples[4] = 0;
    sound->samples[5] = 0.1;
    sound->samples[6] = 0.5;
    sound->samples[7] = 0.2;
    sound->samples[8] = 0;
    sound->samples[9] = 0;
    sound->samples[10] = 0;
    sound->samples[11] = 0;
    sound->samples[12] = 0.2;
    sound->samples[13] = 0.2;
    sound->samples[14] = 0.3;
    sound->samples[15] = 0.3;

    reverb(sound, 0, 0);
    
}