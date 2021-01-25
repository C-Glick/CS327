#include "TriangleWave.h"
float TriangleWave::generateFunction(float time){
    return fabs(fmod(4 * frequency * time, 4) - 2) - 1;
}