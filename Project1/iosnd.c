#include "iosnd.h"

//read the given sound struct and output all
//samples to the given FILE pointer
//returns 0 on success
//returns 1 on failure
int outputSound(Sound* s, FILE* f){
    for(int i=0; i < s->length; i++){
        fprintf(f,"%f\n", *(s->samples + i));
    }
    return 0;
}