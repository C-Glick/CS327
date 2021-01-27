#ifndef SQUARE_WAVE
    #define SQUARE_WAVE
    #include "wave.h"
    #include <string>
    #include <math.h>


    using namespace std;
    class SquareWave : public Wave{
        public:
            SquareWave(string nameIn): Wave(nameIn){}
            virtual float generateFunction(float time);
    };
#endif