#ifndef SINE_WAVE
    #define SINE_WAVE
    #include "wave.h"
    #include <string>
    #include <math.h>


    using namespace std;
    class SineWave : public Wave{
        public:
            SineWave(string nameIn): Wave(nameIn){}
            virtual float generateFunction(float time);
    };
#endif