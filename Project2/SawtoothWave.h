#ifndef Sawtooth_WAVE
    #define Sawtooth_WAVE
    #include "wave.h"
    #include <string>
    #include <math.h>


    using namespace std;
    class SawtoothWave : public Wave{
        public:
            SawtoothWave(string nameIn): Wave(nameIn){}
            virtual float generateFunction(float time);
    };
#endif