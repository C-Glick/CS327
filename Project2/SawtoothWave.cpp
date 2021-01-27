#include "SawtoothWave.h"
float SawtoothWave::generateFunction(float time){
    return 2 * (frequency * time - floor(frequency * time)) - 1;

}