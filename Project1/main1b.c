#include<stdio.h>
#include<stdlib.h>
#include "gensnd.h"

int main(int argc, char *argv[]){
    if(argc <= 1 || argc >3){
        printf("Usage: dtmf <number to dial> <(optional) output file>\n");
        exit(0);
    }

    //validate phone number
    char* c = argv[1];
    while(*c != '\0'){
        switch(*c){
            case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '0': case 'a': case 'b': case 'c':
            case 'd': case 'A': case 'B': case 'C': case 'D': case '*': case '#':
                c++;
                break;
            default:
                fprintf(stderr, "error: '%s' is not a valid string, valid characters are 0-9, a-d, A-D, #, and *.\n", argv[1]);
                exit(1);
        }
    }

    
    FILE* out;
    //no output file given
    if(argc == 2){
        out = stdout;
    //output file given
    }else if(argc == 3){
        out = fopen(argv[2], "w");
        if(out == NULL){
            fprintf(stderr, "Failed to open file");
            exit(1);
        }
    }

    for(c = argv[1]; *c != '\0'; c++){
        Sound* tone = genDTMF2(*(c), 8000, 0.5);
        outputSound(tone, out);
        Sound* silence = genSilence(8000, 0.25);
        outputSound(silence, out);
        
        //free memory used 
        free(tone->samples);
        free(tone);
        free(silence->samples);
        free(silence);
    }


}