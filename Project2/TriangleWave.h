#ifndef TRIANGLE_WAVE
    #define TRIANGLE_WAVE
    #include "wave.h"
    #include <string>
    #include <math.h>


    using namespace std;
    class TriangleWave : public Wave{
        public:
            TriangleWave(string nameIn): Wave(nameIn){}
            virtual float generateFunction(float time);
    };
#endif