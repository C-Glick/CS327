#include "SquareWave.h"
float SquareWave::generateFunction(float time){
    return 2 * (2 * floor(frequency * time) - floor(2 * frequency * time)) + 1;
}