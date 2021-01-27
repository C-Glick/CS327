#include "SineWave.h"
float SineWave::generateFunction(float time){
    return sin(2 * M_PI * frequency * time);
}