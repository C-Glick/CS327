#include<stdio.h>
#include "gensnd.h"

int main(){
    float frequency;
    float sampleRate;
    float length;
    
    printf("Enter frequency (Hz): ");
    if(scanf("%f", &frequency) !=1){return 1;}

    printf("Enter sample rate (Hz): ");
    if(scanf("%f", &sampleRate) !=1){return 1;}

    printf("Enter length (s): ");
    if(scanf("%f", &length) !=1){return 1;} 

    if(frequency <= 0 || sampleRate <= 0 || length <= 0){
        return 1;
    }
    gensine(frequency, sampleRate, length);
    return 0;
}